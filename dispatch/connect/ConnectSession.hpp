#pragma once

namespace cc {
	
	class ConnectSession : noncopyable
	{
	public:
		void sendValue(int16_t nAppId, ValuePtr& nValue);
		
		SessionPtr& createSession(int16_t nAppId);
		
		void runPreinit();
		void runStop();
		
		static ConnectSession& instance();
		
		ConnectSession();
		~ConnectSession();
		
	private:
		static ConnectSession mConnectSession;
		
		map<int16_t, SessionPtr> mSessions;
	};
	
}
