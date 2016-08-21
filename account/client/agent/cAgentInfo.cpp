#include "../../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cAgentInfo::initAgentInfo(cAgentResult& nAgentResult)
	{
		cServerInfo& serverInfo_ = nAgentResult.getServerInfo();
		mServerInfo.setServerInfo(serverInfo_);
		
		mAgentPort = nAgentResult.getAgentPort();
        mAgentIp = nAgentResult.getAgentIp();
	}
	
	const char * cAgentInfo::getAgentPort()
	{
		return mAgentPort.c_str();
	}
	
    const char * cAgentInfo::getAgentIp()
	{
		return mAgentIp.c_str();
	}
	
	cAgentInfo::cAgentInfo()
		: mAgentPort ("")
		, mAgentIp ("")
	{
	}
	
	cAgentInfo::~cAgentInfo()
	{
		mAgentPort = "";
		mAgentIp = "";
	}
#endif
	
}
