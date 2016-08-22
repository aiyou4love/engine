#include "../../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__

	const char * mAccountCheck = "accountCheck";
	const char * mAccountRegister = "accountRegister";
	const char * mAccountLogin = "accountLogin";
	const char * mAgentInfoUrl = "agentInfo";
	const char * mRoleCreate = "roleCreate";
	
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
		return 1;
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
	
	bool cAccountEngine::isLogin()
	{
		cAccountPtr account_ = PTR_CAST<cAccount>(mAccount);
		
		return account_->isLogin();
	}
	
	string cAccountEngine::getServerInfo(int16_t nPageId, int16_t nPageCount)
	{
		list<cServerItemPtr> serverItems_;
		mServerList->getServerItems(serverItems_, nPageId, nPageCount);
		LuaWriter luaWriter_;
		luaWriter_.luaStreamPtrs<list<cServerItemPtr>, cServerItemPtr>(serverItems_, "serverItems");
		return luaWriter_.getLuaValue();
	}
	
	void cAccountEngine::setStartServer(int32_t nServerId, int32_t nRoleId)
	{
		cAccountPtr account_ = PTR_CAST<cAccount>(mAccount);
		
		account_->setServerId(nServerId);
		account_->setRoleId(nRoleId);
	}
	
	string cAccountEngine::getRoleInfos()
	{
		LuaWriter luaWriter_;
		map<int64_t, cRoleItemPtr>& roleItems_ = mRoleList->getRoleItems();
		luaWriter_.luaMapStreamPtrs<map<int64_t, cRoleItemPtr>, cRoleItemPtr>(roleItems_, "roleInfos");
		return luaWriter_.getLuaValue();
	}
	
	void cAccountEngine::getAgentInfo(ValuePtr& nValue)
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		cAccountPtr account_ = PTR_CAST<cAccount>(mAccount);
		int32_t serverId_ = account_->getServerId();
		
		cAgentResult agentResult_;
		cAgentResult * agentResult1_ = &agentResult_;
		if ( !urlMgr_.runUrl(agentResult1_, mAgentInfoUrl, agentResult_.streamName(), operatorName_, versionNo_, serverId_) ) {
			nValue->pushInt8(0);
			return;
		}
		if (1 != agentResult_.getErrorCode()) {
			nValue->pushInt8((int8_t)2);
			return;
		}
		mAgentInfo->initAgentInfo(agentResult_);
		
		const char * agentPort_ = agentResult_.getAgentPort();
        const char * agentIp_ = agentResult_.getAgentIp();
		
		nValue->pushInt8((int8_t)1);
		nValue->pushString(agentIp_);
		nValue->pushString(agentPort_);
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
		mServerList->pushServerItem(serverItem_);
		mRoleList->pushRoleItem(roleItem_);
		return 1;
	}
	
	const char * cAccountEngine::getRoleName(int32_t nServerId, int32_t nRoleId)
	{
		cRoleItemPtr& roleItem_ = mRoleList->getRoleItem(nServerId, nRoleId);
		if (!roleItem_) {
			return roleItem_->getRoleName();
		}
		LOGE("[%s]%d,%d", __METHOD__, nServerId, nRoleId);
		return "";
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
	
	void cAccountEngine::runPreinit()
	{
		mAccount.reset(new cAccount());
		mServerList.reset(new cServerList());
		mRoleList.reset(new cRoleList());
		mAgentInfo.reset(new cAgentInfo());
		
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
