#include "../../Include.hpp"

namespace std {
	
	void DoingEngine::runDoing(int32_t nId, PlayerPtr& nPlayer, ValuePtr& nValue)
	{
		auto it = mDoingMgrs.find(nId);
		if ( it == mDoingMgrs.end() ) {
			LOGERROR("[%s]%d", __METHOD__, nId);
			return;
		}
		DoingMgrPtr& doingMgr_ = it->second;
		doingMgr_->runDoing(nPlayer, nValue);
	}
	
	void DoingEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunConfig.connect(bind(&DoingEngine::runConfig, this));
	}
	
	void DoingEngine::runConfig()
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		urlMgr_.runClass<DoingEngine *>(this);
	}
	
	const char * DoingEngine::streamName()
	{
		return "doingEngine";
	}
	
	const char * DoingEngine::streamUrl()
	{
		return "arc://doingEngine.xml";
	}
	
	DoingEngine& DoingEngine::instance()
	{
		return mDoingEngine;
	}
	
	DoingEngine::DoingEngine()
	{
		mDoingMgrs.clear();
	}
	
	DoingEngine::~DoingEngine()
	{
		mDoingMgrs.clear();
	}
	
	DoingEngine DoingEngine::mDoingEngine;
	
}
