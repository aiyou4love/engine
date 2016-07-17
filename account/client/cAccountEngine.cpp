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
		auto it = mUrlValues.find("accountCheck");
		if ( it == mUrlValues.end() ) {
			LOGE("[%s]", __METHOD__);
			return 3;
		}
		UrlValuePtr urlValue_ = it->second;
		
		const char * url_ = urlValue_->getUrlValue();
		int16_t timeout_ = urlValue_->getTimeout();
		
		boost::format format_(url_);
		format_ % nValue;
		
		HttpCurl httpCurl_;
		CurlString curlString_;
		
		httpCurl_.runInit(format_.str().c_str());
		httpCurl_.runCurlValue(&curlString_);
		httpCurl_.runTimeout(timeout_);
		if ( !httpCurl_.runPerform() ) {
			return 4;
		}
		const char * value_ = curlString_.getValue();
		if ( 0 == strcmp(value_, "false") ) {
			return 2;
		} else if ( 0 == strcmp(value_, "true") ) {
			return 1;
		} else {
			return 0;
		}
	}

	EntityPtr& cAccountEngine::getAccount()
	{
		return mAccount;
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
	{
		mUrlValues.clear();
		mAspects.clear();
	}
	
	cAccountEngine::~cAccountEngine()
	{
		mAccount.reset();
		mUrlValues.clear();
		mAspects.clear();
	}
	
	cAccountEngine cAccountEngine::mAccountEngine;
#endif

}
