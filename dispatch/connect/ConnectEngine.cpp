#include "../../Engine.hpp"

namespace cc {
	
	const char * ConnectEngine::streamName()
	{
		return "connectIp";
	}
	
	const char * ConnectEngine::streamUrl()
	{
		return "connectIp.json";
	}
	
	const char * ConnectEngine::infoName()
	{
		return "connectInfo";
	}
	
	const char * ConnectEngine::infoUrl()
	{
		return "connectInfo.json";
	}
	
	ConnectEngine& ConnectEngine::instance()
	{
		return mConnectEngine;
	}
	
	ConnectEngine::ConnectEngine()
	{
	}
	
	ConnectEngine::~ConnectEngine()
	{
	}
	
	ConnectEngine ConnectEngine::mConnectEngine;
	
}
