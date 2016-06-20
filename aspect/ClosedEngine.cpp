#include "../../Include.hpp"

namespace cc {
	
	void CloseEngine::runDoing(int32_t nId, EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine)
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
	
	bool CloseEngine::runCondition(int32_t nId, EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine)
	{
		map<int32_t, ClosedPtr>::iterator it = mCloseds.find(nId);
		if ( it == mCloseds.end() ) {
			LOGERROR("[%s]%d", __METHOD__, nId);
			return false;
		}
		ClosedPtr& closed_ = it->second;
		return closed_->runCondition(nEntity, nValue, nAspectEngine);
	}
	
	void CloseEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunConfig.connect(bind(&CloseEngine::runConfig, this));
	}
	
	void CloseEngine::runLoad()
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
		return "arc://autoupEngine.json";
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
	
	CloseEngine CloseEngine::mCloseEngine;
	
}
