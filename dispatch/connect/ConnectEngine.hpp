#pragma once

namespace cc {
	
	class ConnectEngine : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int32_t, ConnectInfoPtr>(mConnectInfos, "connectInfos", "connectInfo");
			} else if ( 0 == strcmp(infoName(), nName) ) {
				nSerialize.runMapStreamPtrs<int32_t, ConnectIpPtr>(mConnectIps, "connectIps", "connectIp");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * infoName();
		const char * infoUrl();
		
		static ConnectEngine& instance();
		
		ConnectEngine();
		~ConnectEngine();
		
	private:
		map<int32_t, ConnectInfoPtr> mConnectInfos;
		map<int32_t, ConnectIpPtr> mConnectIps;
		
		static ConnectEngine mConnectEngine;
	};
	
}
