#include "../../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	const char * cAgentResult::streamName()
	{
		return "AgentResult";
	}
	
	const char * cAgentResult::streamUrl()
	{
		return "AgentResult.json";
	}
	
	cServerInfo& cAgentResult::getServerInfo()
	{
		return mServerInfo;
	}
	
	const char * cAgentResult::getAgentPort()
	{
		return mAgentPort.c_str();
	}
	
	const char * cAgentResult::getAgentIp()
	{
		return mAgentIp.c_str();
	}
	
	int32_t cAgentResult::getErrorCode()
	{
		return mErrorCode;
	}
	
	cAgentResult::cAgentResult()
		: mErrorCode (0)
        , mAgentIp("")
        , mAgentPort("")
	{
	}
	
	cAgentResult::~cAgentResult()
	{
		mErrorCode = 0;
		mAgentIp = "";
		mAgentPort = "";
	}
#endif
	
}
