#pragma once

namespace cc {
	
	class AcceptEngine : noncopyable
	{
	private:
		void handleAccept(const boost::system::error_code& nError);
		void startAccept();
		
		void initAccept(const char * nIp, const char * nPort);
		void initAccept(int16_t nIpId);
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runMapStreamPtrs<int16_t, AcceptIpPtr>(mAcceptIps, "acceptIps", "acceptIp");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void stopEnd();
		void runClear();
		
		static AcceptEngine& instance();
		
		AcceptEngine();
		~AcceptEngine();
		
	private:
		std::shared_ptr<asio::ip::tcp::acceptor> mAcceptor;
		
		map<int16_t, AcceptIpPtr> mAcceptIps;
		
		SessionPtr * mNewSession;
		
		static AcceptEngine mAcceptEngine;
	};
	
}
