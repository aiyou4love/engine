#pragma once

namespace cc {
	
	class ConnectEngine : noncopyable
	{
	public:
		void initConnect(EntityPtr& nEntity, const char * nIp, const char * nPort, const char * nInfoId);
		void initConnect(EntityPtr& nEntity, ConnectIpPtr& nConnectIp, ConnectInfoPtr& nConnectInfo);
		void initConnect(EntityPtr& nEntity, const char * nIpId, const char * nInfoId);
				
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int16_t, ConnectInfoPtr>(mConnectInfos, "connectInfos", "connectInfo");
			} else if ( 0 == strcmp(infoName(), nName) ) {
				nSerialize.runMapStreamPtrs<int16_t, ConnectIpPtr>(mConnectIps, "connectIps", "connectIp");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * infoName();
		const char * infoUrl();
		
		void runPreinit();
		void runLoad();
		
		static ConnectEngine& instance();
		
		ConnectEngine();
		~ConnectEngine();
		
	private:
		map<int16_t, ConnectInfoPtr> mConnectInfos;
		map<int16_t, ConnectIpPtr> mConnectIps;
		map<int16_t, ConnectorPtr> mConnectors;
		
		int32_t mConnectId;
		
		static ConnectEngine mConnectEngine;
	};
	
}
