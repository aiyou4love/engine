#include "../../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__

	const char * mAccountCheck = "accountCheck";
	const char * mAccountRegister = "accountRegister";
	const char * mAccountLogin = "accountLogin";
	
	int8_t cAccountEngine::runLogin(const char * nName, const char * nPassword, int16_t nAccountType)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		cLoginResult loginResult_;
		cLoginResult * loginResult1_ = &loginResult_;
		if ( !urlMgr_.runUrl(loginResult1_, mAccountLogin, loginResult_.streamName(), nName, nPassword, operatorName_, versionNo_, nAccountType) ) {
			return 0;
		}
		cServerItem& serverItem_ = loginResult_.getServerItem();
		cRoleItem& roleItem_ = loginResult_.getRoleItem();
		
		cAccountPtr account_ = PTR_CAST<cAccount>(mAccount);
		account_->setAccountName(nName);
		account_->setAccountPassword(nPassword);
		account_->setAccountType(nAccountType);
		account_->initAccountInfo(loginResult_);
		account_->runSave();
		mServerList->pushServerItem(serverItem_);
		mServerList->runSave();
		mRoleList->pushRoleItem(roleItem_);
		mRoleList->runSave();
		return 0;
	}
	
	int8_t cAccountEngine::runRegister(const char * nName, const char * nPassword)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		string value_;
		if ( !urlMgr_.runUrl(value_, mAccountRegister, "", nName, nPassword) ) {
			return 0;
		}
		if ("false" == value_) {
			return 2;
		} else if ("true" == value_) {
			return 1;
		} else {
			return 3;
		}
	}
	
	int8_t cAccountEngine::isRegister(const char * nValue)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		string value_;
		if ( !urlMgr_.runUrl(value_, mAccountCheck, "", nValue) ) {
			return 0;
		}
		if ("false" == value_) {
			return 2;
		} else if ("true" == value_) {
			return 1;
		} else {
			return 3;
		}
	}
	
	void cAccountEngine::runCancel()
	{
		cAccountPtr account_ = PTR_CAST<cAccount>(mAccount);
		
		account_->runReset();
		account_->runSave();
		mRoleList->runClear();
		mRoleList->runSave();
		mServerList->runClear();
		mServerList->runSave();
	}
	
	const char * cAccountEngine::getServerName(int32_t nServerId)
	{
		cServerItemPtr& serverItem_ = mServerList->getServerItem(nServerId);
		return serverItem_->getServerName();
	}
	
	EntityPtr& cAccountEngine::getAccount()
	{
		return mAccount;
	}
	
	void cAccountEngine::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<cAccountEngine>("cAccountEngine");
		luaEngine_.runStatic<cAccountEngine>(cAccountEngine::instance, "instance");
		luaEngine_.runMethod<cAccountEngine>(&cAccountEngine::getAccount, "getAccount");
	}
	
	void cAccountEngine::runLoad()
	{
		cAccountPtr account_ = PTR_CAST<cAccount>(mAccount);
		
		account_->runLoad();
		mServerList->runLoad();
		mRoleList->runLoad();
	}
	
	void cAccountEngine::runClear()
	{
		mAccount.reset();
		mServerList.reset();
		mRoleList.reset();
	}
	
	void cAccountEngine::runPreInit()
	{
		mAccount.reset(new cAccount());
		mServerList.reset(new cServerList());
		mRoleList.reset(new cRoleList());
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&cAccountEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&cAccountEngine::runLoad, this));
		lifeCycle_.m_tRunClear.connect(bind(&cAccountEngine::runClear, this));
	}
	
	cAccountEngine& cAccountEngine::instance()
	{
		return mAccountEngine;
	}
	
	cAccountEngine::cAccountEngine()
	{
	}
	
	cAccountEngine::~cAccountEngine()
	{
	}
	
	cAccountEngine cAccountEngine::mAccountEngine;
#endif
	
}
