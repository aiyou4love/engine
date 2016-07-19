#include "../../Engine.hpp"

namespace cc {
	
	const char * RoleResult::streamName()
	{
		return "roleResult";
	}
	
	const char * RoleResult::streamUrl()
	{
		return "roleResult.json";
	}
	
	ServerItem& RoleResult::getServerItem()
	{
		return mServerItem;
	}
	
	RoleItem& RoleResult::getRoleItem()
	{
		return mRoleItem;
	}
	
	int64_t RoleResult::getAccountId()
	{
		return mAccountId;
	}
	
	int32_t RoleResult::getErrorCode()
	{
		return mErrorCode;
	}
	
	RoleResult::RoleResult()
		: mAccountId (0)
		, mErrorCode (0)
	{
	}
	
	RoleResult::~RoleResult()
	{
		mAccountId = 0;
		mErrorCode = 0;
	}
		
}
