#include "../../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cRoleItem::luaValue(LuaWriter * nLuaWriter, const char * nName)
	{
		cAccountEngine& accountEngine_ = cAccountEngine::instance();
		const char * serverName_ = accountEngine_.getServerName(mServerId);
		
		nLuaWriter->runNumber(mServerId, "mServerId");
		nLuaWriter->runNumber(serverName_, "serverName");
		nLuaWriter->runNumber(mRoleId, "mRoleId");
		nLuaWriter->runNumber(mRoleType, "mRoleType");
		nLuaWriter->runNumber(mRoleName, "mRoleName");
		nLuaWriter->runNumber(mRoleRace, "mRoleRace");
		nLuaWriter->runNumber(mRoleStep, "mRoleStep");
		nLuaWriter->runNumber(mRoleLevel, "mRoleLevel");
	}
	
	int32_t cRoleItem::getServerId()
	{
		return mServerId;
	}
	
	int32_t cRoleItem::getRoleId()
	{
		return mRoleId;
	}
	
	int16_t cRoleItem::getRoleType()
	{
		return mRoleType;
	}
	
	const char * cRoleItem::getRoleName()
	{
		return mRoleName.c_str();
	}
	
    int16_t cRoleItem::getRoleRace()
	{
		return mRoleRace;
	}
	
	int16_t cRoleItem::getRoleStep()
	{
		return mRoleStep;
	}
	
	int32_t cRoleItem::getRoleLevel()
	{
		return mRoleLevel;
	}
	
	int64_t cRoleItem::getId()
	{
		int64_t result_ = mServerId;
		result_ <<= 32;
		return (result_ | mRoleId);
	}
	
	int64_t cRoleItem::getKey()
	{
		return getId();
	}
	
	bool cRoleItem::isDefault()
	{
		return ( (0 == mServerId ) || (0 == mRoleId )
				|| (0 == mRoleType ) || ("" == mRoleName )
				|| (0 == mRoleRace ) || (0 == mRoleStep )
				|| (0 == mRoleLevel ) );
	}
	
	cRoleItem::cRoleItem()
		: mServerId (0)
		, mRoleId (0)
		, mRoleType (0)
		, mRoleName ("")
		, mRoleRace (0)
		, mRoleStep (0)
		, mRoleLevel (0)
	{
	}
	
	cRoleItem::cRoleItem(cRoleItem& nRoleItem)
		: mServerId (nRoleItem.mServerId)
		, mRoleId (nRoleItem.mRoleId)
		, mRoleType (nRoleItem.mRoleType)
		, mRoleName (nRoleItem.mRoleName)
		, mRoleRace (nRoleItem.mRoleRace)
		, mRoleStep (nRoleItem.mRoleStep)
		, mRoleLevel (nRoleItem.mRoleLevel)
	{
	}
	
	cRoleItem::~cRoleItem()
	{
		mServerId = 0;
		mRoleId = 0;
		mRoleType = 0;
		mRoleName = "";
		mRoleRace = 0;
		mRoleStep = 0;
		mRoleLevel = 0;
	}
#endif
	
}
