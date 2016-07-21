#include "../../Engine.hpp"

namespace cc {
	
	void ServerItem::luaValue(LuaWriter * nLuaWriter, const char * nName)
	{
		if (0 == strcmp(nName, "pageServes")) {			
			nLuaWriter->runNumber(mServerId, "serverId");
			nLuaWriter->runNumber(mServerName, "serverName");
			nLuaWriter->runNumber(mServerNo, "serverNo");
		}
	}
	
	int32_t ServerItem::getServerId()
	{
		return mServerId;
	}
	
	const char * ServerItem::getServerName()
	{
		return mServerName.c_str();
	}
	
	int16_t ServerItem::getServerNo()
	{
		return mServerNo;
	}
	
	bool ServerItem::isDefault()
	{
		return (0 == mServerId);
	}
	
	int32_t ServerItem::getKey()
	{
		return (0 == mServerId);
	}
	
	ServerItem::ServerItem()
		: mServerId (0)
		, mServerName ("")
		, mServerNo (0)
	{
	}
	
	ServerItem::ServerItem(ServerItem& nServerItem)
		: mServerId (nServerItem.mServerId)
		, mServerName (nServerItem.mServerName)
		, mServerNo (nServerItem.mServerNo)
	{	
	}
	
	ServerItem::~ServerItem()
	{
		mServerId = 0;
		mServerName = "";
		mServerNo = 0;
	}
	
}
