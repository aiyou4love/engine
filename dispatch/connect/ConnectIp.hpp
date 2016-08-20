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
		int16_t getKey();
		
		ConnectIp();
		ConnectIp(const char * nIp, const char * nPort);
		~ConnectIp();
		
	private:
		int16_t mConnectIpId;
		string mServerPort;
		string mServerIp;
	};
	typedef SPTR<ConnectIp> ConnectIpPtr;
	
}
