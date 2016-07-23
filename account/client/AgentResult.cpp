#include "../../Engine.hpp"

namespace cc {
	
	const char * AgentResult::streamName()
	{
		return "AgentResult";
	}
	
	const char * AgentResult::streamUrl()
	{
		return "AgentResult.json";
	}
	
	ServerInfo& AgentResult::getServerInfo()
	{
		return mServerInfo;
	}
	
	const char * AgentResult::getAgentPort()
	{
		return mAgentPort.c_str();
	}
	
	const char * AgentResult::getAgentIp()
	{
		return mAgentIp.c_str();
	}
	
	int32_t AgentResult::getErrorCode()
	{
		return mErrorCode;
	}
	
	AgentResult::AgentResult()
		: mErrorCode (0)
        , mAgentIp("")
        , mAgentPort("")
	{
	}
	
	AgentResult::~AgentResult()
	{
		mErrorCode = 0;
		mAgentIp = "";
		mAgentPort = "";
	}
	
}
