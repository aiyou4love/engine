#include "../Engine.hpp"

namespace cc {
	
	DispatchPtr& ApplicationEngine::getDispatch()
	{
		return mDispatch;
	}
	
	EntityPtr& ApplicationEngine::getEntity()
	{
		return mEntity;
	}
	
	void ApplicationEngine::runPreinit()
	{
		mEntity.reset(new Application());
		mDispatch.reset(new ApplicationDispatch());
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tClearEnd.connect(bind(&ApplicationEngine::runClear, this));
	}
	
	void ApplicationEngine::runClear()
	{
		AspectEngine::runClear();
		
		mDispatch.reset();
		mEntity.reset();
	}
	
	ApplicationEngine& ApplicationEngine::instance()
	{
		return mApplicationEngine;
	}
	
	ApplicationEngine::ApplicationEngine()
	{
		this->runClear();
	}
	
	ApplicationEngine::~ApplicationEngine()
	{
		this->runClear();
	}
	
	ApplicationEngine ApplicationEngine::mApplicationEngine;
	
}
