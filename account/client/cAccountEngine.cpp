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
