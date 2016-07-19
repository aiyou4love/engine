#include "../../Engine.hpp"

namespace cc {
	
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
	
	bool Account::isStartRole()
	{
		return ( (mServerId > 0) && (mRoleId > 0) );
	}
	
	bool Account::isLogin()
	{
		return (mAccountId > 0);
	}
	
	Account::Account()
		: mAccountId (0)
		, mServerId (0)
		, mRoleId (0)
	{
	}
	
	Account::~Account()
	{
		mAccountId = 0;
		mServerId = 0;
		mRoleId = 0;
	}
	
}
