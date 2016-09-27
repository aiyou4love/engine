#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	const char * mRegisterUrl = "accountRegister";
	const char * mLoginUrl = "accountLogin";
	const char * mCheckUrl = "accountCheck";
	
	int8_t cAccountEngine::runLogin(const char * nName, const char * nPassword, int16_t nType)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		cLoginResult loginResult_;
		if ( !urlMgr_.runStream(loginResult_, mLoginUrl, loginResult_.streamName(), nName, nPassword, operatorName_, versionNo_, nType) ) {
			return 0;
		}
		RoleItemPtr& roleItem_ = loginResult_.getRoleItem();
		RoleEngine& roleEngine_ = RoleEngine::instance();
		roleEngine_.pushRoleItem(roleItem_);
		roleEngine_.runSave();
		
		int64_t accountId_ = loginResult_.getAccountId();
		int16_t authority_ = loginResult_.getAuthority();
		cAccountPtr account_ = PTR_CAST<cAccount>(mAccount);
		account_->setName(nName);
		account_->setPassword(nPassword);
		account_->setType(nType);
		account_->setAuthority(authority_);
		account_->setId(accountId_);
		account_->runSave();
		return 1;
	}
	
	int8_t cAccountEngine::runRegister(const char * nName, const char * nPassword)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		string value_;
		if ( !urlMgr_.runNumber(value_, mRegisterUrl, nName, nPassword) ) {
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
	
	int8_t cAccountEngine::isRegister(const char * nName)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		string value_;
		if ( !urlMgr_.runNumber(value_, mCheckUrl, nValue) ) {
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
		
		account_->runClear();
		account_->runSave();
	}
	
	int8_t cAccountEngine::roleCreate(const char * nRoleName, int16_t nRoleRace)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		cAccountPtr account_ = PTR_CAST<cAccount>(mAccount);
		
		const char * accountName_ = account_->getAccountName();
		const char * password_ = account_->getAccountPassword();
		int16_t accountType_ = account_->getAccountType();
		int64_t accountId_ = account_->getAccountId();
		int32_t serverId_ = account_->getServerId();
		bool update_ = !(account_->isStartRole());
		
		cRoleResult roleResult_;
		cRoleResult * roleResult1_ = &roleResult_;
		if ( !urlMgr_.runUrl(roleResult1_, mRoleCreate, roleResult_.streamName(), accountName_, password_, accountType_,
			operatorName_, versionNo_, accountId_, serverId_, nRoleName, nRoleRace, update_) ) {
			return 0;
		}
		cServerItem& serverItem_ = roleResult_.getServerItem();
		cRoleItem& roleItem_ = roleResult_.getRoleItem();
		account_->setServerId(roleItem_.getServerId());
		account_->setRoleId(roleItem_.getRoleId());
		account_->runSave();
		mServerList->pushServerItem(serverItem_);
		mServerList->runSave();
		mRoleList->pushRoleItem(roleItem_);
		mRoleList->runSave();
		return 1;
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
		cAccountPtr account_ = PTR_DCST<cAccount>(mAccount);
		
		account_->runLoad();
	}
	
	void cAccountEngine::runClear()
	{
		mAccount.reset();
	}
	
	void cAccountEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		
		lifeCycle_.m_tRunLuaApi.connect(bind(&cAccountEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&cAccountEngine::runLoad, this));
		lifeCycle_.m_tRunClear.connect(bind(&cAccountEngine::runClear, this));
		
		mAccount.reset(new cAccount());
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
