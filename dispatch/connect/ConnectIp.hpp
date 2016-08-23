#pragma once

namespace cc {
	
	class ConnectIp : noncopyable
	{
	public:
		const char * getServerUrl();
		
		int32_t getConnectErrorId();
		int32_t getConnectId();
		int32_t getTimeoutId();
		
		int32_t getDisconnectId();
		int32_t getExceptionId();
		int16_t getDispatchId();
		
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
