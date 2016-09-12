#include "../../Engine.hpp"

namespace cc {
	
	void Account::setRoleName(const char * nRoleName)
	{
		mRoleName = nRoleName;
	}
	
	void Account::setAccountId(int64_t nAccountId)
	{
		mAccountId = nAccountId;
	}
	
	void Account::setServerId(int32_t nServerId)
	{
		mServerId = nServerId;
	}
	
	void Account::setRoleId(int32_t nRoleId)
	{
		mRoleId = nRoleId;
	}
	
	void Account::setRoleLevel(int16_t nRoleLevel)
	{
		mRoleLevel = nRoleLevel;
	}
	
	void Account::setRoleType(int16_t nRoleType)
	{
		mRoleType = nRoleType;
	}
	
	void Account::setRoleRace(int16_t nRoleRace)
	{
		mRoleRace = nRoleRace;
	}
	
	void Account::setRoleStep(int16_t nRoleStep)
	{
		mRoleStep = nRoleStep;
	}
	
	const char * Account::getRoleName()
	{
		return "";
	}
	
	int64_t Account::getAccountId()
	{
		return mAccountId;
	}
	
	int32_t Account::getRoleId()
	{
		return mRoleId;
	}
	
	int32_t Account::getServerId()
	{
		return mServerId;
	}
	
	int16_t Account::getRoleLevel()
	{
		return mRoleLevel;
	}
	
	int16_t Account::getRoleType()
	{
		return mRoleType;
	}
	
	int16_t Account::getRoleRace()
	{
		return mRoleRace;
	}
	
	int16_t Account::getRoleStep()
	{
		return mRoleStep;
	}
	
	Account::Account()
		: mAccountId (0)
		, mServerId (0)
		, mRoleId (0)
		, mRoleName ("")
		, mRoleType (0)
		, mRoleRace (0)
		, mRoleStep (0)
		, mRoleLevel (0)
	{
	}
	
	Account::~Account()
	{
		mAccountId = 0;
		mServerId = 0;
		mRoleId = 0;
		mRoleName = "";
		
		mRoleType = 0;
		mRoleRace = 0;
		mRoleStep = 0;
		mRoleLevel = 0;
	}
	
}
