#include "../../Engine.hpp"

namespace cc {
	
	void Session::startRead()
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
			this->runClose();
			this->runException();
		}
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
