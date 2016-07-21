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

	void cAccount::setAccountName(const char * nAccountName)
	{
		mAccountName = nAccountName;
	}

	void cAccount::setAccountPassword(const char * nPassword)
	{
		mAccountPassword = nPassword;
	}

	void cAccount::setAccountType(int16_t nAccountType)
	{
		mAccountType = nAccountType;
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
	
	const char * cAccount::streamName()
	{
		return "account";
	}
	
	const char * cAccount::streamUrl()
	{
		return "account.json";
	}
	
	void cAccount::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<cAccount *>(this, streamUrl(), streamName());
	}
	
	void cAccount::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<cAccount *>(this, streamUrl(), streamName());
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
