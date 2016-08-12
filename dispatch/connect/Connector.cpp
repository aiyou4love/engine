#include "../../Engine.hpp"

namespace cc {
	
	void Connector::runConnect(ConnectIpPtr& nConnectIp, ConnectInfoPtr& nConnectInfo)
	{
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		
		const char * serverPort_ = nConnectIp->getServerPort();
		const char * serverIp_ = nConnectIp->getServerIp();
		
		asio::ip::tcp::resolver resolver_(ioHandle_);
		asio::ip::tcp::resolver::query query_(serverIp_, serverPort_);
		asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
		
		try {
			boost::asio::async_connect((*mSession)->getSocket(), iterator_,
			boost::bind(&Connector::handleConnect, this, boost::asio::placeholders::error));
			
			mConnectTimer.expires_from_now(boost::posix_time::seconds(TcpConnector::connect_timeout));
			mConnectTimer.async_wait(boost::bind(&TcpConnector::handleConnectTimeout, 
				this, boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runException();
		}
	}
	
	void Connector::handleConnectTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runException();
			return;
		}
		if (mConnectTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mConnectTimer.expires_at(boost::posix_time::pos_infin);
			
			this->runTimeout();
		}
	}
	
	void TcpConnector::handleConnect(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runException();
			return;
		}
		mConnectTimer.cancel();
		mClosed = false;
		this->runRead();
		this->runConnect();
	}
	
	Connector::Connector(int16_t nConnectId, asio::io_service& nHandle)
		: mConnectTimer (nHandle)
		, mConnectId (nConnectId)
	{
		SessionMgr& sessionMgr_ = SessionMgr::instance();
		mSession = &(sessionMgr_.createSession());
	}
	
	Connector::~Connector()
	{
	}
	
}
