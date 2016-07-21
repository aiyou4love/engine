#pragma once

namespace cc {
	
	class AgentResult : noncopyable
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
		
		ServerInfo& getServerInfo();
		int32_t getAgentPort();
		const char * getAgentIp();
		int32_t getErrorCode();
		
		AgentResult();
		~AgentResult();
		
	private:
        ServerInfo mServerInfo;
        int32_t mAgentPort;
        int32_t mErrorCode;
        string mAgentIp;
	};
	typedef std::shared_ptr<AgentResult> AgentResultPtr;
	
}
