#pragma once

namespace cc {
	
	class TcpConnector : public Session
	{
	public:
		void runConnector(asio::ip::tcp::resolver::iterator& nIterator, ConnectInfo& nConnectInfo);
		
		void runDisconnect();
		void runConnect();
		void runException();
		void runTimeout();
		void runClose();
		
	private:
		void handleConnectTimeout(const boost::system::error_code& nError);
		void handleConnect(const boost::system::error_code& nError);
		
	public:
		enum { connect_timeout = 90 };
		
		TcpConnector(asio::io_service& nIoService);
		~TcpConnector();
		
	private:
		asio::deadline_timer mConnectTimer;
		
		int32_t mDisconnectId;
		int32_t mTimeoutId;
		int32_t mConnectId;
		int32_t mExceptionId;
	};
	typedef std::shared_ptr<TcpConnector> TcpConnectorPtr;
	
}
