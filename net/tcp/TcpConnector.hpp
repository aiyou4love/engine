#pragma once

namespace cc {
	
	class TcpConnector : public Session
	{
	public:
		void runConnector(asio::ip::tcp::resolver::iterator& nIterator, int32_t nConnectId, int32_t nDisconnectId);
		
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
	};
	typedef std::shared_ptr<TcpConnector> TcpConnectorPtr;
	
}
