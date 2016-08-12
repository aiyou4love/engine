#pragma once

namespace cc {
	
	class SessionMgr: noncopyable
	{
	public:
		void removeSession(int32_t nSessionId);
		SessionPtr& createSession();
		
		void runPreinit();
		void runClear();
		
		SessionMgr();
		~SessionMgr();
		
	private:
		map<int32_t, SessionPtr> mSessions;
		int32_t mSessionId;
		
		mutex mMutex;
	};
	
}
