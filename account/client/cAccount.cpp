#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	EdoingState cAccount::runCondition(DoingPtr& nDoing, ValuePtr& nValue)
	{
		cAccountEngine& accountEngine_ = cAccountEngine::instance();
		return accountEngine_.runCondition(nDoing, nValue);
	}
	
	void cAccount::runReward(DoingPtr& nDoing, ValuePtr& nValue)
	{
		cAccountEngine& accountEngine_ = cAccountEngine::instance();
		accountEngine_.runReward(nDoing, nValue);
	}
	
	const char * cAccount::getAccountName()
	{
		return mAccountName.c_str();
	}
	
	const char * cAccount::getAccountPassword()
	{
		return mAccountPassword.c_str();
	}
	
	int16_t cAccount::getAccountType()
	{
		return mAccountType;
	}
	
	void cAccount::runReset()
	{
		mAccountId = 0;
		mServerId = 0;
		mRoleId = 0;
		
		mAccountName = "";
		mAccountPassword = "";
		mAccountType = 0;
	}
	
	const char * cAccount::getRoleName()
	{
		cAccountEngine& accountEngine_ = cAccountEngine::instance();
		return accountEngine_.getRoleName(mServerId, mRoleId);
	}
	
	cAccount::cAccount()
		: mAccountName ("")
		, mAccountPassword ("")
		, mAccountType (0)
	{
	}
	
	cAccount::~cAccount()
	{
		mAccountName = "";
		mAccountPassword = "";
		mAccountType = 0;
	}
#endif

}
