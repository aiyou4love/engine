#include "../../Engine.hpp"

namespace cc {
	
	int8_t ConditionEngine::runCondition(int32_t nConditionId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mConditions.find(nConditionId);
		if ( it == mConditions.end() ) {
			LOGERROR("[%s]%d", __METHOD__, nConditionId);
			return 0x2;
		}
		ConditionPtr& condition_ = it->second;
		return condition_->runCondition(nEntity, nValue);
	}
	
	void ConditionEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&ConditionEngine::runLoad, this));
	}
	
	void ConditionEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runTable<ConditionEngine *>(this, streamUrl(), streamName());
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
