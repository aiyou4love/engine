#include "../Engine.hpp"

namespace cc {
	
	EntityPtr& ApplicationEngine::getEntity()
	{
		return mEntity;
	}
	
	void ApplicationEngine::runPreinit()
	{
		mEntity.reset(new Application());
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunClear.connect(bind(&ApplicationEngine::runClear, this));
	}
	
	void ApplicationEngine::runClear()
	{
		AspectEngine::runClear();
		
		mEntity.reset();
	}
	
	ApplicationEngine& ApplicationEngine::instance()
	{
		return mApplicationEngine;
	}
	
	ApplicationEngine::ApplicationEngine()
	{
		mEntity.reset();
	}
	
	ApplicationEngine::~ApplicationEngine()
	{
	}
	
	ApplicationEngine ApplicationEngine::mApplicationEngine;
	
}
