#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	bool runCondition(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue)
	{
		cAccountEngine& accountEngine_ = cAccountEngine::instance();
		return accountEngine_.runCondition(nEntity, nDoing, nValue);
	}
	
	void cAccount::runReward(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue)
	{
		cAccountEngine& accountEngine_ = cAccountEngine::instance();
		accountEngine_.runReward(nEntity, nDoing, nValue);
	}
	
	void cAccount::initAccountInfo(cLoginResult& nLoginResult)
	{
		RoleItem& roleItem_ = loginResult_.getRoleItem();
		mAccountId =loginResult_.getAccountId();
		mAuthority =loginResult_.getAuthority();
		mServerId =roleItem_.getServerId();
		mRoleId =roleItem_.getRoleId();
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
	
	const char * cAccount::streamName()
	{
		return "account";
	}
	
	const char * cAccount::streamUrl()
	{
		return "account.json";
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
