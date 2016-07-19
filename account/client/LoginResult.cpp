#include "../../Engine.hpp"

namespace cc {
	
	const char * LoginResult::streamName()
	{
		return "loginResult";
	}
	
	const char * LoginResult::streamUrl()
	{
		return "loginResult.json";
	}
	
	ServerItem& LoginResult::getServerItem()
	{
		return mServerItem;
	}
	
	RoleItem& LoginResult::getRoleItem()
	{
		return mRoleItem;
	}
	
	int64_t LoginResult::getAccountId()
	{
		return mAccountId;
	}
	
	LoginResult::LoginResult()
		: mAccountId (0)
	{
	}
	
	LoginResult::~LoginResult()
	{
		mAccountId = 0;
	}
		
}
