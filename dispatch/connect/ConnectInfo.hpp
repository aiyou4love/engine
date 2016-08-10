#pragma once

namespace cc {
	
	class ConnectInfo : noncopyable
	{
	public:
		void setDisconnectId(int32_t nDisconnectId);
		void setExceptionId(int32_t nExceptionId);
		void setConnectId(int32_t nConnectId);
		void setTimeoutId(int32_t nTimeoutId);
		
		int32_t getDisconnectId();
		int32_t getExceptionId();
		int32_t getConnectId();
		int32_t getTimeoutId();
		
		ConnectInfo();
		~ConnectInfo();
		
	private:
		int32_t mDisconnectId;
		int32_t mExceptionId;
		int32_t mConnectId;
		int32_t mTimeoutId;
	};
	typedef std::shared_ptr<ConnectInfo> ConnectInfPtr;
	
}
