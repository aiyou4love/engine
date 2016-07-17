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
