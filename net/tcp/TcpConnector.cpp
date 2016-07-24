#include "../../Engine.hpp"

namespace cc {
	
	void TcpConnector::runConnector(asio::ip::tcp::resolver::iterator& nIterator, int32_t nConnectId, int32_t nDisconnectId)
	{
		mDisconnectId = nDisconnectId;
		mConnectId = nConnectId;
		
		try {
			boost::asio::async_connect(mSocket, nIterator,
			boost::bind(&TcpConnector+::handleConnect, this, boost::asio::placeholders::error));
			
			mConnectTimer.expires_from_now(boost::posix_time::seconds(TcpConnector::connect_timeout));
			mConnectTimer.async_wait(boost::bind(&TcpConnector::handleConnectTimeout, 
				this, boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
		}
	}
	
	void TcpConnector::handleConnectTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
		}
		if (mConnectTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			mConnectTimer.expires_at(boost::posix_time::pos_infin);
		}
	}
	
	void TcpConnector::handleConnect(const boost::system::error_code& nError)
	{
		mConnectTimer.cancel();
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			return;
		}
		this->runRecv();
	}
	
	TcpConnector::TcpConnector(asio::io_service& nIoService)
		: mConnectTimer (nIoService)
		, Session (nIoService)
		, mDisconnectId (0)
		, mConnectId (0)
	{
	}
	
	TcpConnector::~TcpConnector()
	{
		mDisconnectId = 0;
		mConnectId = 0;
	}
	
}
