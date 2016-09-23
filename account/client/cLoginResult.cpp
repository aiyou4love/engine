#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	const char * cLoginResult::streamName()
	{
		return "loginResult";
	}
	
	const char * cLoginResult::streamUrl()
	{
		return "loginResult.json";
	}
	
	RoleItemPtr& cLoginResult::getRoleItem()
	{
		return mRoleItem;
	}
	
	int64_t cLoginResult::getAccountId()
	{
		return mAccountId;
	}
	
	int16_t cLoginResult::getAuthority()
	{
		return mAuthority;
	}
	
	cLoginResult::cLoginResult()
		: mAccountId (0)
		, mAuthority (0)
		, mRoleItem (new RoleItem())
	{
	}
	
	cLoginResult::~cLoginResult()
	{
		mAccountId = 0;
		mAuthority = 0;
	}
#endif
	
}
