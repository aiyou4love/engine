#include "../../Include.hpp"

namespace std {
	
	void CloseEngine::runDoing(int32_t nId, PlayerPtr& nPlayer, ValuePtr& nValue)
	{
		auto it = mDoingMgrs.find(nId);
		if ( it == mDoingMgrs.end() ) {
			LOGERROR("[%s]%d", __METHOD__, nId);
			return;
		}
		DoingMgrPtr& doingMgr_ = it->second;
		doingMgr_->runDoing(nPlayer, nValue);
	}
	
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
	
	const char * CloseEngine::streamUrl()
	{
		return "arc://closeEngine.xml";
	}
	
	CloseEngine& CloseEngine::instance()
	{
		return mCloseEngine;
	}
	
	CloseEngine::CloseEngine()
	{
		mDoingMgrs.clear();
	}
	
	CloseEngine::~CloseEngine()
	{
		mDoingMgrs.clear();
	}
	
	CloseEngine CloseEngine::mCloseEngine;
	
}
