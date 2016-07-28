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
		
	}
	
	void Session::runWrite()
	{
		try {
			mWriteTimer.expires_from_now(boost::posix_time::seconds(Session::write_timeout));
			mWriteTimer.async_wait(boost::bind(&Session::handleWriteTimeout,
				shared_from_this(), boost::asio::placeholders::error));
				
			//asio::async_write(mSocket, boost::asio::buffer(mWriteBlock->getBuffer(), mWriteBlock->getTotal()),
			//	boost::bind(&Session::handleWrite, shared_from_this(), asio::placeholders::error));
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
		mReadTimer.cancel();
		this->internalRead();
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
	
	void Session::internalRead()
	{
		
	}
	
	void Session::runRead()
	{
		try {
			mReadTimer.expires_from_now(boost::posix_time::seconds(Session::read_timeout));
			mReadTimer.async_wait(boost::bind(&Session::handleReadTimeout, 
				shared_from_this(), boost::asio::placeholders::error));
				
			//mSocket.async_read_some(boost::asio::buffer(mReadBuffer),
			//	boost::bind(&Session::handleRead, shared_from_this(),
			//	asio::placeholders::error, asio::placeholders::bytes_transferred));
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
		mWriteTimer.cancel();
		mReadTimer.cancel();
	}
	
	Session::Session(asio::io_service& nIoService)
		: mSocket (nIoService)
		, mWriteTimer (nIoService)
		, mReadTimer (nIoService)
	{
	}
	
	Session::~Session()
	{
		this->runClose();
	}
	
}
