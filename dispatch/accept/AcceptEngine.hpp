#pragma once

namespace cc {
	
	class AcceptEngine : noncopyable
	{
	private:
		void handleAccept(const boost::system::error_code& nError);
		void startAccept(const char * nIp, char * nPort);
		void startAccept();
		
	public:
		void runPreinit();
		void startBegin();
		void stopEnd();
		
		AcceptEngine();
		~AcceptEngine();
		
	private:
		std::shared_ptr<asio::ip::tcp::acceptor> mAcceptor;
		
		SessionPtr * mNewSession;
	};
	
}
