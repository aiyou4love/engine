#pragma once

namespace cc {
	
	class SessionMgr: noncopyable
	{
	public:
		void removeSession(int32_t nSessionId);
		SessionPtr& createSession();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runMapStreamPtrs<int16_t, AcceptInfoPtr>(mAcceptInfos, "acceptInfos", "acceptInfo");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runStop();
		
		static SessionMgr& instance();
		
		SessionMgr();
		~SessionMgr();
		
	private:
		map<int16_t, AcceptInfoPtr> mAcceptInfos;
		
		map<int32_t, SessionPtr> mSessions;
		
		int32_t mSessionId;
		mutex mMutex;
		
		static SessionMgr mSessionMgr;
	};
	
}
