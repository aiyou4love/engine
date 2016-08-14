#include "../../Engine.hpp"

namespace cc {
	
	SessionPtr SessionMgr::createSession()
	{
		int32_t sessionId_ = 0;
		{
			lock_guard<mutex> lock_(mMutex);
			++mSessionId;
			sessionId_ = mSessionId;
		}
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		return session_( new Session(sessionId_, ioHandle_) );
	}
	
	SessionMgr& SessionMgr::instance()
	{
		return mSessionMgr;
	}
	
	SessionMgr::SessionMgr()
		: mSessionId (0)
	{
	}
	
	SessionMgr::~SessionMgr()
	{
		mSessionId = 0;
	}
	
	static SessionMgr mSessionMgr;
	
}
