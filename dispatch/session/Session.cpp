#include "../../Engine.hpp"

namespace cc {
	
	void Session::handleWriteTimeout(const boost::system::error_code& nError)
	{
		if (mWriteTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mWriteTimer.expires_at(boost::posix_time::pos_infin);
			
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runDisconnect();
		}
	}
	
	void Session::handleWrite(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runException();
			return;
		}
		mWriteTimer.cancel();
		this->internalWrite();
		this->runWrite();
	}
	
	void Session::internalWrite()
	{
		ValuePtr value_ = this->popValue();
		if (!value_) {
			mWriting = false;
			return;
		}
		mBufWriter.runClear();
		IoWriter<BufWriter> ioWriter_(mBufWriter);
		value_->headSerialize(ioWriter_, "");
		mBufWriter.runEnd();
	}
	
	void Session::runWrite()
	{
		try {
			mWriteTimer.expires_from_now(boost::posix_time::seconds(Session::write_timeout));
			mWriteTimer.async_wait(boost::bind(&Session::handleWriteTimeout,
				shared_from_this(), boost::asio::placeholders::error));
				
			asio::async_write(mSocket, boost::asio::buffer(mBufWriter.getValue(), mBufWriter.getSize()),
				boost::bind(&Session::handleWrite, shared_from_this(), asio::placeholders::error));
			mWriting = true;
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runException();
		}
	}
	
	void Session::runSend(ValuePtr& nValue)
	{
		if ( mClosed ) {
			LOGE("[%s]socket closed", __METHOD__);
			return;
		}
		this->pushValue(nValue);
		if (false == mWriting) {
			this->internalWrite();
			this->runWrite();
		}
	}
	
	void Session::pushValue(ValuePtr& nValue)
	{
		std::lock_guard<mutex> lock_(mMutex);
		mValues.push_back(nValue);
	}
	
	ValuePtr Session::popValue()
	{
		std::lock_guard<mutex> lock_(mMutex);
		ValuePtr value_;
		if (mValues.size() > 0) {
			value_ = mValues.front();
			mValues.pop_front();
		}
		return value_;
	}
	
	void Session::handleRead(const boost::system::error_code& nError, size_t nBytes)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runException();
			return;
		}
		mReadTimer.cancel();
		this->internalRead(nBytes);
		this->runRead();
	}
	
	void Session::handleReadTimeout(const boost::system::error_code& nError)
	{
		if (mReadTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mReadTimer.expires_at(boost::posix_time::pos_infin);
			
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runDisconnect();
		}
	}
	
	void Session::internalRead(size_t nBytes)
	{
		char * buf_ = (char *)(mReadBuffer.data());
		int16_t size_ = (int16_t)nBytes;
		EpushBuf pushBuf_ = mBufReader.pushBuf(buf_, size_);
		if (EpushBuf::mError == pushBuf_) {
			LOGE("[%s]pushBuf:%d", __METHOD__, (int8_t)pushBuf_);
			this->runException();
			return;
		}
		if (EpushBuf::mLength == pushBuf_) {
			return;
		}
		ValuePtr value_(new Value());
		IoReader<BufReader> ioReader_(mBufReader);
		value_->headSerialize(ioReader_, "");
		(*mEntity)->pushValue(value_);
		mBufReader.finishBuf();
		mReadBuffer.assign(0);
	}
	
	void Session::runRead()
	{
		try {
			mReadTimer.expires_from_now(boost::posix_time::seconds(Session::read_timeout));
			mReadTimer.async_wait(boost::bind(&Session::handleReadTimeout, 
				shared_from_this(), boost::asio::placeholders::error));
				
			mSocket.async_read_some(boost::asio::buffer(mReadBuffer),
				boost::bind(&Session::handleRead, shared_from_this(),
				asio::placeholders::error, asio::placeholders::bytes_transferred));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runException();
		}
	}
	
	void Session::runDisconnect()
	{
		this->runClose();
		
		if (mExceptionId > 0) {
			ValuePtr value_(new Value());
			value_->pushInt32(mExceptionId);
			(*mEntity)->pushValue(value_);
		}
	}
	
	void Session::runException()
	{
		this->runClose();
		
		if (mDisconnectId > 0) {
			ValuePtr value_(new Value());
			value_->pushInt32(mDisconnectId);
			(*mEntity)->pushValue(value_);
		}
	}
	
	void Session::runClear()
	{
		this->runClose();
		
		mReadBuffer.fill(0);
		mValues.clear();
		
		mDisconnectId = 0;
		mExceptionId = 0;
		mEntity = nullptr;
	}
	
	void Session::runClose()
	{
		if (mSocket.is_open()) {
			boost::system::error_code error_;
			mSocket.shutdown(asio::socket_base::shutdown_both, error_);
			mSocket.close(error_);
		}
		mWriteTimer.cancel();
		mReadTimer.cancel();
		mClosed = true;
		mWriting = false;
	}
	
	void Session::setDisconnect(int32_t nDisconnectId)
	{
		mDisconnectId = nDisconnectId;
	}
	
	void Session::setException(int32_t nExceptionId)
	{
		mExceptionId = nExceptionId;
	}
	
	void Session::setEntity(EntityPtr& nEntity)
	{
		mEntity = &nEntity;
	}
	
	Session::Session(asio::io_service& nIoService)
		: mSocket (nIoService)
		, mWriteTimer (nIoService)
		, mReadTimer (nIoService)
		, mClosed (true)
		, mWriting(false)
		, mEntity (nullptr)
	{
		mReadBuffer.fill(0);
		mValues.clear();
	}
	
	Session::~Session()
	{
		this->runClear();
	}
	
}
