#pragma once

namespace cc {
	
	class Connector : noncopyable
	{
	public:
		void runConnect(ConnectIpPtr& nConnectIp, ConnectInfoPtr& nConnectInfo);
		
	private:
		void handleConnectTimeout(const boost::system::error_code& nError);
		void handleConnect(const boost::system::error_code& nError);
		
		void runDisconnect();
		void runConnect();
		void runException();
		void runTimeout();
		
	public:
		enum { connect_timeout = 90 };
		
		Connector(int16_t nConnectId, asio::io_service& nHandle);
		~Connector();
		
	private:
		asio::deadline_timer mConnectTimer;
		
		SessionPtr * mSession;
		int32_t mConnectId;
		int32_t mConnectId;
		int16_t mConnectId;
	};
	typedef std::shared_ptr<Connector> ConnectorPtr;
	
}
