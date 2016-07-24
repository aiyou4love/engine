#pragma once

namespace cc {
	
	class cNetEngine : public NetEngine
	{
	public:
		void initNet(EntityPtr& nEntity, const char * nIp, const char * nPort, int32_t nConnectId, int32_t nDisconnectId);
		void sendNet(EntityPtr& nEntity, ValuePtr& nValue);
		
		static cNetEngine& instance();
		
		cNetEngine();
		~cNetEngine();
		
	private:
		static cNetEngine mNetEngine;
	};
	
}
