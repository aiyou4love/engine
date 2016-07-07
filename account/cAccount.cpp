#include "../../Engine.hpp"

namespace cc {
	
	EdoingState cAccount::runCondition(DoingPtr& nDoing, ValuePtr& nValue)
	{
		
	}
	
	void cAccount::runReward(DoingPtr& nDoing, ValuePtr& nValue)
	{
		
	}
	
	const char * cAccount::streamName()
	{
		return "cAccount";
	}
	
	const char * cAccount::streamUrl()
	{
		return "cAccount.json";
	}
	
	cAccount::cAccount()
		: mAccountName ("")
		, mAccountPassword ("")
		, mAccountType (1)
		, mIsLoad (false)
	{
	}
	
	cAccount::~cAccount()
	{
		mAccountName = "";
		mAccountPassword = "";
		mAccountType = 1;
		mIsLoad = true;
	}
	
}
