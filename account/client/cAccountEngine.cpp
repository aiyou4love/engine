#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	EdoingState cAccountEngine::runCondition(DoingPtr& nDoing, ValuePtr& nValue)
	{
		LOGF;
		
		int32_t aspectId_= nDoing->getAspectId();
		int32_t doingId_= nDoing->getDoingId();
		auto it = mAspects.find(aspectId_);
		if ( it == mAspects.end() ) {
			LOGE("[%s]%d", __METHOD__, aspectId_);
			return EdoingState::mError;
		}
		IAspect * aspect_ = it->second;
		return aspect_->runCondition(doingId_, mAccount, nValue);
	}
	
	void cAccountEngine::runReward(DoingPtr& nDoing, ValuePtr& nValue)
	{
		LOGF;
		
		int32_t aspectId_= nDoing->getAspectId();
		int32_t doingId_= nDoing->getDoingId();
		auto it = mAspects.find(aspectId_);
		if ( it == mAspects.end() ) {
			LOGE("[%s]%d", __METHOD__, aspectId_);
			return;
		}
		IAspect * aspect_ = it->second; 
		return aspect_->runReward(doingId_, mAccount, nValue);
	}
	
	void cAccountEngine::registerAspect(int32_t nAspectId, IAspect * nAspect)
	{
		LOGF;
		
		auto it = mAspects.find(nAspectId);
		if ( it != mAspects.end() ) {
			LOGE("[%s]%d", __METHOD__, nAspectId);
			return;
		}
		mAspects[nAspectId] = nAspect;
	}
	
	int8_t cAccountEngine::isRegister(const char * nValue)
	{
		string value_;
		int8_t errorCode_ = runHttp(value_, 1, nValue);
		if (1 != errorCode_) {
			return errorCode_;
		}
		if ("false" == value_) {
			return 2;
		} else if ("true" == value_) {
			return 1;
		} else {
			return 0;
		}
	}
	
	int8_t cAccountEngine::registerAccount(const char * nName, const char * nPassword)
	{
		string value_;
		int8_t errorCode_ = runHttp(value_, 2, nName, nPassword);
		if (1 != errorCode_) {
			return errorCode_;
		}
		if ("false" == value_) {
			return 2;
		} else if ("true" == value_) {
			return 1;
		} else {
			return 0;
		}
	}
	
	int8_t cAccountEngine::loginAccount(const char * nName, const char * nPassword, int16_t nAccountType)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		string value_;
		int8_t errorCode_ = runHttp(value_, 3, nName, nPassword, operatorName_, versionNo_, nAccountType);
		if (1 != errorCode_) {
			return errorCode_;
		}
		LoginResult loginResult_;
		this->runClass(&loginResult_, value_, loginResult_.streamName());
		int64_t accountId_ = loginResult_.getAccountId();
		if (0 == accountId_) {
			return 2;
		}
		cAccountPtr account_ = std::dynamic_pointer_cast<cAccount>(mAccount);
		ServerItem& serverItem_ = loginResult_.getServerItem();
		RoleItem& roleItem_ = loginResult_.getRoleItem();
		account_->setAccountId(loginResult_.getAccountId());
		account_->setServerId(roleItem_.getServerId());
		account_->setRoleId(roleItem_.getRoleId());
		mServerList->pushServerItem(serverItem_);
		mRoleList->pushRoleItem(roleItem_);
		return 1;
	}
	
	void cAccountEngine::cancelAccount(int64_t nAccountId)
	{
		cAccountPtr account_ = std::dynamic_pointer_cast<cAccount>(mAccount);
		account_->runReset();
		
		mRoleList->runClear();
	}
	
	int8_t cAccountEngine::accountEnter()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		cAccountPtr account_ = std::dynamic_pointer_cast<cAccount>(mAccount);
		int32_t serverId_ = account_->getServerId();
		
		string value_;
		int8_t errorCode_ = runHttp(value_, 6, operatorName_, versionNo_, serverId_);
		if (1 != errorCode_) {
			return errorCode_;
		}
		AgentResult agentResult_;
		this->runClass(&agentResult_, value_, agentResult_.streamName());
		if (1 != agentResult_.getErrorCode()) {
			return 2;
		}
		
		mServerInfo.setServerInfo(agentResult_.getServerInfo());
        mAgentPort = agentResult_.getAgentPort();
        mAgentIp = agentResult_.getAgentIp();
		
		return 1;
	}
	
	void cAccountEngine::selectServer(int32_t nServerId, int32_t nRoleId)
	{
		cAccountPtr account_ = std::dynamic_pointer_cast<cAccount>(mAccount);
		account_->setServerId(nServerId);
		account_->setRoleId(nRoleId);
	}
	
	string cAccountEngine::startServers()
	{
		LuaWriter luaWriter_;
		map<int64_t, RoleItemPtr>& roleItems_ = mRoleList->getRoleItems();
		luaWriter_.luaMapStreamPtrs<map<int64_t, RoleItemPtr>, RoleItemPtr>(roleItems_, "startServers");
		return luaWriter_.getLuaValue();
	}
	
	string cAccountEngine::pageServers(int16_t nPageId, int16_t nPageCount)
	{
		list<ServerItemPtr> serverItems_;
		mServerList->pageServers(serverItems_, nPageId, nPageCount);
		LuaWriter luaWriter_;
		luaWriter_.luaStreamPtrs<list<ServerItemPtr>, ServerItemPtr>(serverItems_, "pageServes");
		return luaWriter_.getLuaValue();
	}
	
	int8_t cAccountEngine::roleCreate(const char * nRoleName, int16_t nRoleRace)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		cAccountPtr account_ = std::dynamic_pointer_cast<cAccount>(mAccount);
		const char * accountName_ = account_->getAccountName();
		const char * password_ = account_->getAccountPassword();
		int16_t accountType_ = account_->getAccountType();
		int64_t accountId_ = account_->getAccountId();
		int32_t serverId_ = account_->getServerId();
		bool update_ = !(account_->isStartRole());
		
		string value_;
		int8_t errorCode_ = runHttp(value_, 7, accountName_, password_, accountType_, operatorName_, versionNo_,
			accountId_, serverId_, nRoleName, nRoleRace, update_);
		if (1 != errorCode_) {
			return errorCode_;
		}
		RoleResult roleResult_;
		this->runClass(&roleResult_, value_, roleResult_.streamName());
		
		ServerItem& serverItem_ = roleResult_.getServerItem();
		RoleItem& roleItem_ = roleResult_.getRoleItem();
		account_->setServerId(roleItem_.getServerId());
		account_->setRoleId(roleItem_.getRoleId());
		mServerList->pushServerItem(serverItem_);
		mRoleList->pushRoleItem(roleItem_);
		
		account_->runSave();
		mServerList->runSave();
		mRoleList->runSave();
		
		return 1;
	}
	
	const char * cAccountEngine::getRoleName(int32_t nServerId, int32_t nRoleId)
	{
		RoleItemPtr roleItem_ = mRoleList->getRoleItem(nServerId, nRoleId);
		if (!roleItem_) {
			return roleItem_->getRoleName();
		}
		LOGE("[%s]%d,%d", __METHOD__, nServerId, nRoleId);
		return "";
	}
	
	EntityPtr& cAccountEngine::getAccount()
	{
		return mAccount;
	}
	
	void cAccountEngine::runFormat(boost::format& nFormat)
	{
	}
	
	void cAccountEngine::runPreinit()
	{
		LOGF;
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&cAccountEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&cAccountEngine::runLoad, this));
	}
	
	void cAccountEngine::runLuaApi()
	{
		LOGF;
		
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<cAccountEngine>("cAccountEngine");
		luaEngine_.runStatic<cAccountEngine>(cAccountEngine::instance, "instance");
		luaEngine_.runMethod<cAccountEngine>(&cAccountEngine::getAccount, "getAccount");
	}
	
	void cAccountEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runTable<cAccountEngine *>(this, streamUrl(), streamName());
		
		cAccountPtr account_ = std::dynamic_pointer_cast<cAccount>(mAccount);
		account_->runLoad();
		mRoleList->runLoad();
		mServerList->runLoad();
	}
	
	const char * cAccountEngine::streamName()
	{
		return "accountEngine";
	}
	
	const char * cAccountEngine::streamUrl()
	{
		return "accountEngine.json";
	}
	
	const char * cAccountEngine::saveName()
	{
		return "cAccountEngine";
	}
	
	const char * cAccountEngine::saveUrl()
	{
		return "cAccountEngine.json";
	}
	
	cAccountEngine& cAccountEngine::instance()
	{
		LOGF;
		
		return mAccountEngine;
	}
	
	cAccountEngine::cAccountEngine()
		: mAccount (new cAccount())
		, mRoleList (new cRoleList())
		, mAgentPort(0)
		, mAgentIp("")
	{
		mUrlValues.clear();
		mAspects.clear();
	}
	
	cAccountEngine::~cAccountEngine()
	{
		mAccount.reset();
		mRoleList.reset();
		mUrlValues.clear();
		mAspects.clear();
		mAgentPort = 0;
		mAgentIp = "";
	}
	
	cAccountEngine cAccountEngine::mAccountEngine;
#endif

}
