#pragma once

namespace cc {
	
	class ConnectIp : noncopyable
	{
	public:
		const char * getServerPort();
		const char * getServerIp();
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mConnectIpId, "connectIpId");
			nSerialize->runNumber(mServerPort, "serverPort");
			nSerialize->runNumber(mServerIp, "serverIp");
		}
		bool isDefault();
		int32_t getKey();
		
		ConnectIp();
		~ConnectIp();
		
	private:
		string mServerPort;
		string mServerIp;
	};
	typedef std::shared_ptr<ConnectIp> ConnectIpPtr;
	
}
