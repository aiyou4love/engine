#include "../../Engine.hpp"

namespace cc {
	
	void SessionMgr::removeSession(int32_t nSessionId)
	{
		lock_guard<mutex> lock_(mMutex);
		auto it = mSessions.find(nSessionId);
		if (it == mSessions.end()) {
			LOGE("[%s]%d", __METHOD__, nSessionId);
			return;
		}
		mSessions.erase(it);
	}
	
	SessionPtr& SessionMgr::createSession()
	{
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		
		lock_guard<mutex> lock_(mMutex);
		SessionPtr session_(new Session(++mSessionId, ioHandle_));
		mSessions[mSessionId] = session_;
		return mSessions[mSessionId];
	}
	
	void SessionMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tStopEnd.connect(bind(&SessionMgr::runStop, this));
	}
	
	void SessionMgr::runStop()
	{
		mSessions.clear();
	}
	
	SessionMgr& SessionMgr::instance()
	{
		return mSessionMgr;
	}
	
	SessionMgr::SessionMgr()
		: mSessionId (0)
	{
		mSessions.clear();
	}
	
	SessionMgr::~SessionMgr()
	{
		mSessions.clear();
		mSessionId = 0;
	}
	
	static SessionMgr mSessionMgr;
	
}
