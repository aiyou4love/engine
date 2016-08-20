#pragma once

namespace cc {
	
	class AcceptIp : noncopyable
	{
	public:
		const char * getServerPort();
		const char * getServerIp();
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mAcceptIpId, "acceptIpId");
			nSerialize->runNumber(mServerPort, "serverPort");
			nSerialize->runNumber(mServerIp, "serverIp");
		}
		bool isDefault();
		int16_t getKey();
		
		AcceptIp();
		~AcceptIp();
		
	private:
		int16_t mAcceptIpId;
		string mServerPort;
		string mServerIp;
	};
	typedef SPTR<AcceptIp> AcceptIpPtr;
	
}
