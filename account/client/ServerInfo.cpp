#include "../../Engine.hpp"

namespace cc {
	
	void ServerInfo::setServerInfo(ServerInfo& nServerInfo)
	{
		mServerStart = nServerInfo.mServerStart;
	}
	
	int64_t ServerInfo::getServerStart()
	{
		return mServerStart;
	}
	
	ServerInfo::ServerInfo()
		: mServerStart (0)
	{
	}
	
	ServerInfo::ServerInfo(ServerInfo& nServerInfo)
		: mServerStart (nServerInfo.mServerStart)
	{
	}
	
	ServerInfo::~ServerInfo()
	{
		mServerStart = 0;
	}
	
}
