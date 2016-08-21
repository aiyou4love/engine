#include "../../../Engine.hpp"

namespace cc {
	
	const char * cRoleResult::streamName()
	{
		return "roleResult";
	}
	
	const char * cRoleResult::streamUrl()
	{
		return "roleResult.json";
	}
	
	cServerItem& cRoleResult::getServerItem()
	{
		return mServerItem;
	}
	
	cRoleItem& cRoleResult::getRoleItem()
	{
		return mRoleItem;
	}
	
	int64_t cRoleResult::getAccountId()
	{
		return mAccountId;
	}
	
	int32_t cRoleResult::getErrorCode()
	{
		return mErrorCode;
	}
	
	cRoleResult::cRoleResult()
		: mAccountId (0)
		, mErrorCode (0)
	{
	}
	
	cRoleResult::~cRoleResult()
	{
		mAccountId = 0;
		mErrorCode = 0;
	}
		
}