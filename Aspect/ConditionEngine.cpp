#include "../../Include.hpp"

namespace cc {
	
	void ConditionEngine::runDoing(int32_t nId, EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine)
	{
		map<int32_t, ClosedPtr>::iterator it = mCloseds.find(nId);
		if ( it == mCloseds.end() ) {
			LOGERROR("[%s]%d", __METHOD__, nId);
			return;
		}
		ClosedPtr& closed_ = it->second;
		if ( closed_->runCondition(nEntity, nValue, nAspectEngine) ) {
			closed_->runDoing(nEntity, nValue, nAspectEngine);
		}
	}
	
	void ConditionEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunConfig.connect(bind(&CloseEngine::runConfig, this));
	}
	
	void ConditionEngine::runLoad()
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		urlMgr_.runClass<ConditionEngine *>(this);
	}
	
	const char * ConditionEngine::streamName()
	{
		return "conditionEngine";
	}
	
	const char * ConditionEngine::streamUrl()
	{
		return "arc://conditionEngine.json";
	}
	
	ConditionEngine& ConditionEngine::instance()
	{
		return mConditionEngine;
	}
	
	ConditionEngine::ConditionEngine()
	{
		mConditions.clear();
	}
	
	ConditionEngine::~ConditionEngine()
	{
		mConditions.clear();
	}
	
	ConditionEngine ConditionEngine::mConditionEngine;
	
}
