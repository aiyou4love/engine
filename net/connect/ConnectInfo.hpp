#pragma once

namespace cc {
	
	class ConnectInfo : noncopyable
	{
	public:
		ConnectInfo();
		~ConnectInfo();
		
	private:
		string mServerIp;
		string mServerPort;
		int32_t mConnectId;
		int32_t mCTimeoutId;
		int32_t mDisconnectId;
	};
	typedef std::shared_ptr<ConnectInfo> ConnectInfPtr;
	
}
