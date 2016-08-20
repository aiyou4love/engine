#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cServerItem::luaValue(LuaWriter * nLuaWriter, const char * nName)
	{
		nLuaWriter->runNumber(mServerId, "serverId");
		nLuaWriter->runNumber(mServerName, "serverName");
		nLuaWriter->runNumber(mServerNo, "serverNo");
	}
	
	int32_t cServerItem::getServerId()
	{
		return mServerId;
	}
	
	const char * cServerItem::getServerName()
	{
		return mServerName.c_str();
	}
	
	int16_t cServerItem::getServerNo()
	{
		return mServerNo;
	}
	
	bool cServerItem::isDefault()
	{
		return (0 == mServerId);
	}
	
	int32_t cServerItem::getKey()
	{
		return mServerId;
	}
	
	cServerItem::cServerItem()
		: mServerId (0)
		, mServerName ("")
		, mServerNo (0)
	{
	}
	
	cServerItem::cServerItem(cServerItem& nServerItem)
		: mServerId (nServerItem.mServerId)
		, mServerName (nServerItem.mServerName)
		, mServerNo (nServerItem.mServerNo)
	{
	}
	
	cServerItem::~cServerItem()
	{
		mServerId = 0;
		mServerName = "";
		mServerNo = 0;
	}
#endif
	
}
