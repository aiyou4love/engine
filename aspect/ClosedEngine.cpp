#include "../../Include.hpp"

namespace std {
	
	void CloseEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunConfig.connect(bind(&CloseEngine::runConfig, this));
	}
	
	void CloseEngine::runConfig()
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		urlMgr_.runClass<CloseEngine *>(this);
	}
	
	const char * CloseEngine::streamName()
	{
		return "closeEngine";
	}
	
	CloseEngine& CloseEngine::instance()
	{
		return mCloseEngine;
	}
	
	CloseEngine::CloseEngine()
	{
		mCloseds.clear();
	}
	
	CloseEngine::~CloseEngine()
	{
		mCloseds.clear();
	}
		
}
