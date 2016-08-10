#pragma once

namespace cc {
	
	class ConnectIp : noncopyable
	{
	public:
		void setServerPort(const char * nServerPort);
		void setServerIp(const char * nServerIp);
		
		const char * getServerPort();
		const char * getServerIp();
		
		ConnectIp();
		~ConnectIp();
		
	private:
		string mServerPort;
		string mServerIp;
	};
	typedef std::shared_ptr<ConnectIp> ConnectIpPtr;
	
}
