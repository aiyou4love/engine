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
		this->runWrite();
	}
	
	void Session::runWrite()
	{
		try {
			mWriteTimer.expires_from_now(boost::posix_time::seconds(Session::write_timeout));
			mWriteTimer.async_wait(boost::bind(&Session::handleWriteTimeout,
				shared_from_this(), boost::asio::placeholders::error));
				
			asio::async_write(mSocket, boost::asio::buffer(mWriteBlock->getBuffer(), mWriteBlock->getTotal()),
				boost::bind(&Session::handleWrite, shared_from_this(), asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runException();
		}
	}
	
	void Session::handleRead(const boost::system::error_code& nError, size_t nBytes)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runException();
			return;
		}
		mWriteTimer.cancel();
		this->runWrite();
		
		mReadTimer.cancel();
		if (nError) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(nError.message()));
			this->runClose();
			return;
		}
		BlockPushType_ blockPushType_ = mReadBlock->runPush(mReadBuffer.data(), nBytes);
		if (BlockPushType_::mError_ == blockPushType_) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1("mBlockPushTypeError_ == blockPushType_"));
			this->runClose();
			return;
		}
		if (BlockPushType_::mLength_ == blockPushType_) return;
		ProtocolService& protocolService_ = Service<ProtocolService>::instance();
		if (!protocolService_.runReadBlock(mReadBlock, shared_from_this())) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1("protocolService_.runReadBlock"));
			this->runClose();
			return;
		}
		mReadBlock->endPush();
		mReadBuffer.assign(0);
		this->runStart();
	}
	
	void Session::handleReadTimeout(const boost::system::error_code& nError)
	{
		if (mReadTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mReadTimer.expires_at(boost::posix_time::pos_infin);
			
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runDisconnect();
		}
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
	}
	
	void Session::runException()
	{
		this->runClose();
	}
	
	void Session::runClose()
	{
		if (mSocket.is_open()) {
			boost::system::error_code error_;
			mSocket.shutdown(asio::socket_base::shutdown_both, error_);
			mSocket.close(error_);
		}
	}
	
	Session::Session(asio::io_service& nIoService)
		: mSocket (nIoService)
	{
	}
	
	Session::~Session()
	{
		this->runClose();
	}
	
}
