#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAgentInfo : noncopyable
	{
	public:
		void initAgentInfo(cAgentResult& nAgentResult);
		
		const char * getAgentPort();
        const char * getAgentIp();
		
		cAgentInfo();
		~cAgentInfo();
		
	private:
		cServerInfo mServerInfo;
		
        string mAgentPort;
        string mAgentIp;
	};
	typedef SPTR<cAgentInfo> cAgentInfoPtr;
#endif
	
}
