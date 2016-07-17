#include "../../Engine.hpp"

namespace cc {
	
	int8_t ConditionEngine::runCondition(int32_t nConditionId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		LOGF;
		
		auto it = mConditions.find(nConditionId);
		if ( it == mConditions.end() ) {
			LOGE("[%s]%d", __METHOD__, nConditionId);
			return 0x2;
		}
		ConditionPtr& condition_ = it->second;
		return condition_->runCondition(nEntity, nValue);
	}
	
	void ConditionEngine::runPreinit()
	{
		LOGF;
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&ConditionEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&ConditionEngine::runLoad, this));
	}
	
	void ConditionEngine::runLuaApi()
	{
		LOGF;
		
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<ConditionEngine>("ConditionEngine");
		luaEngine_.runStatic<ConditionEngine>(ConditionEngine::instance, "instance");
		luaEngine_.runMethod<ConditionEngine>(&ConditionEngine::runCondition, "runCondition");
	}
	
	void ConditionEngine::runLoad()
	{
		LOGF;
		
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runTable<ConditionEngine *>(this, streamUrl(), streamName());
	}
	
	const char * ConditionEngine::streamName()
	{
		return "conditionEngine";
	}
	
	const char * ConditionEngine::streamUrl()
	{
		return "conditionEngine.json";
	}
	
	ConditionEngine& ConditionEngine::instance()
	{
		LOGF;
		
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
