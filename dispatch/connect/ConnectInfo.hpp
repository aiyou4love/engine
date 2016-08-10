#pragma once

namespace cc {
	
	class ConnectInfo : noncopyable
	{
	public:
		void setServerIp(const char * nServerIp);
		void setServerPort(const char * nServerPort);
		void setConnectId(int32_t nConnectId);
		void setTimeoutId(int32_t nTimeoutId);
		void setDisconnectId(int32_t nDisconnectId);
		void setExceptionId(int32_t nExceptionId);
		
		const char * getServerIp();
		const char * getServerPort();
		int32_t getConnectId();
		int32_t getTimeoutId();
		int32_t getDisconnectId();
		int32_t getExceptionId();
		
		ConnectInfo();
		~ConnectInfo();
		
	private:
		string mServerIp;
		string mServerPort;
		int32_t mConnectId;
		int32_t mTimeoutId;
		int32_t mDisconnectId;
		int32_t mExceptionId;
	};
	typedef std::shared_ptr<ConnectInfo> ConnectInfPtr;
	
}
