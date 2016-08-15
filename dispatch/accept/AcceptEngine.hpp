#pragma once

namespace cc {
	
	class AcceptEngine : noncopyable
	{
	private:
		void handleAccept(const boost::system::error_code& nError);
		void startAccept(const char * nIp, char * nPort);
		void startAccept();
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int16_t, ConnectInfoPtr>(mConnectInfos, "connectInfos", "connectInfo");
			} else if ( 0 == strcmp(infoName(), nName) ) {
				nSerialize.runMapStreamPtrs<int16_t, ConnectIpPtr>(mConnectIps, "connectIps", "connectIp");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * infoName();
		const char * infoUrl();
		
		void runPreinit();
		void runLoad();
		void startBegin();
		void stopEnd();
		
		AcceptEngine();
		~AcceptEngine();
		
	private:
		std::shared_ptr<asio::ip::tcp::acceptor> mAcceptor;
		
		SessionPtr * mNewSession;
	};
	
}
