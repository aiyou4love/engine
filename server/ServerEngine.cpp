#include "../../../Engine.hpp"

namespace cc {
	
	const char * ServerEngine::streamName()
	{
		return "serverEngine";
	}
	
	const char * ServerEngine::streamUrl()
	{
		return "serverEngine.json";
	}
	
	void ServerEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&ServerEngine::runLoad, this));
		lifeCycle_.m_tInitBegin.connect(bind(&ServerEngine::runInit, this));
		lifeCycle_.m_tClearEnd.connect(bind(&HandleEngine::runClear, this));
	}
	
	void ServerEngine::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<ServerEngine *>(this, streamUrl(), streamName());
	}
	
	const char * mServerUrl = "serverList";
	void ServerEngine::runInit()
	{
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		if ( !urlMgr_.runStream(this, mServerUrl, streamName(), operatorName_, versionNo_) ) {
			LOGE("[%s]%s", __METHOD__, mServerUrl);
			return;
		}
	}
	
	void ServerEngine::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<ServerEngine *>(this, streamUrl(), streamName());
	}
	
	void ServerEngine::runClear()
	{
		mServerItems.clear();
	}
	
	ServerEngine& ServerEngine::instance()
	{
		return mServerEngine;
	}
	
	ServerEngine::ServerEngine()
	{
		mServerItems.clear();
	}
	
	ServerEngine::~ServerEngine()
	{
		mServerItems.clear();
	}
	
	ServerEngine ServerEngine::mServerEngine;
	
}
