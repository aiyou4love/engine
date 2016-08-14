#pragma once

namespace cc {
	
	class SessionMgr: noncopyable
	{
	public:
		SessionPtr createSession();
		
		static SessionMgr& instance();
		
		SessionMgr();
		~SessionMgr();
		
	private:
		static SessionMgr mSessionMgr;
		
		int32_t mSessionId;
		mutex mMutex;
	};
	
}
