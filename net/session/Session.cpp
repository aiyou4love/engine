#include "../../Engine.hpp"

namespace cc {
	
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
