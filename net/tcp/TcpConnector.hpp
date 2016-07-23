#pragma once

namespace cc {
	
	class TcpConnector : public Session
	{
	public:
		void runConnector(string& nIp, string& nPort, int32_t nConnectId, int32_t nDisconnectId);
		
	private:
		void handleConnectTimeout(const boost::system::error_code& nError);
		void handleConnect(const boost::system::error_code& nError);
		void runDisconnect();
		
	public:
		enum { connect_timeout = 90 };
		
		TcpConnector(asio::io_service& nIoService);
		~TcpConnector();
		
	private:
		DeadlineTimerPtr mConnectTimer;
		
		int32_t mDisconnectId;
		int32_t mConnectId;
	};
	typedef std::shared_ptr<TcpConnector> TcpConnectorPtr;
	
}
