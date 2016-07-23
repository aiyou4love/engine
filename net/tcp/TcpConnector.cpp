#include "../../Engine.hpp"

namespace cc {
	
	void TcpConnector::runConnector(string& nIp, string& nPort, int32_t nConnectId, int32_t nDisconnectId)
	{
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioservice = ioService_.getIoService();
		mConnectTimer.reset(new asio::deadline_timer(ioservice));
		
		asio::ip::tcp::resolver resolver_(ioservice);
		asio::ip::tcp::resolver::query query_(nIp, nPort);
		asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
		
		try {
			boost::asio::async_connect(session_->getSocket(), iterator_,
				boost::bind(&TcpClient::handleConnect, this,
				boost::asio::placeholders::error));
			mConnectTimer->expires_from_now(boost::posix_time::seconds(TcpClient::connect_timeout));
			mConnectTimer->async_wait(boost::bind(&TcpConnector::handleConnectTimeout, 
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
		if (mConnectTimer->expires_at() <= asio::deadline_timer::traits_type::now()) {
			this->close();
			LOGE("[%s]%s", __METHOD__, nError.message());
			mConnectTimer->expires_at(boost::posix_time::pos_infin);
		}
	}
	
	void TcpConnector::handleConnect(const boost::system::error_code& nError)
	{
		mConnectTimer->cancel();
		if (nError) {
			this->runDisconnect();
			LOGE("[%s]%s", __METHOD__, nError.message());
			return;
		}
		PlayerPtr& player_ = SingletonPtr<Player>::instance();
		SessionPtr& session_ = player_->getSession();
		session_->openSession();
	}
	
	void TcpConnector::runDisconnect()
	{
		
	}
	
	TcpConnector::TcpConnector(asio::io_service& nIoService)
		: Session (nIoService)
		: mDisconnectId (0)
		, mConnectId (0)
	{
		mConnectTimer.reset();
	}
	
	TcpConnector::~TcpConnector()
	{
		mConnectTimer.reset();
		mDisconnectId = 0;
		mConnectId = 0;
	}
	
}
