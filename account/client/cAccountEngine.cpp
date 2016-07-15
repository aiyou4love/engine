#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	EdoingState cAccountEngine::runCondition(DoingPtr& nDoing, ValuePtr& nValue)
	{
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
	
	void cAccountEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&cAccountEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&cAccountEngine::runLoad, this));
	}
	
	void cAccountEngine::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<cAccountEngine>("cAccountEngine");
		luaEngine_.runStatic<cAccountEngine>(cAccountEngine::instance, "instance");
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
