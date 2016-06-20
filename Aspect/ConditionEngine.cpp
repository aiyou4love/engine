#include "../../Include.hpp"

namespace cc {
	
	bool ConditionEngine::runCondition(int32_t nId, EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine)
	{
		map<int32_t, ClosedPtr>::iterator it = mCloseds.find(nId);
		if ( it == mCloseds.end() ) {
			LOGERROR("[%s]%d", __METHOD__, nId);
			return false;
		}
		ClosedPtr& closed_ = it->second;
		return closed_->runCondition(nEntity, nValue, nAspectEngine);
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
