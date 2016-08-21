#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAgentResult : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mErrorCode, "mErrorCode");
			nSerialize.runNumber(mAgentIp, "mAgentIp");
			nSerialize.runNumber(mAgentPort, "mAgentPort");
			nSerialize.runStream(mServerInfo, "mServerInfo");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		cServerInfo& getServerInfo();
		const char * getAgentPort();
		const char * getAgentIp();
		int32_t getErrorCode();
		
		cAgentResult();
		~cAgentResult();
		
	private:
        cServerInfo mServerInfo;
        int32_t mErrorCode;
        string mAgentPort;
        string mAgentIp;
	};
	typedef SPTR<cAgentResult> cAgentResultPtr;
#endif
	
}
