#pragma once

namespace cc {
	
	class cNetEngine : public NetEngine
	{
	public:
		void initNet(EntityPtr& nEntity, const char * nIp, int32_t nPort, int32_t nRewardId);
		void sendNet(EntityPtr& nEntity, ValuePtr& nValue);
		
		static cNetEngine& instance();
		
		cNetEngine();
		~cNetEngine();
		
	private:
		static cNetEngine mNetEngine;
	};
	
}
