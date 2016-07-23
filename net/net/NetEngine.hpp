#pragma once

namespace cc {
	
	class NetEngine : noncopyable
	{
	public:
		virtual void initNet(EntityPtr& nEntity, const char * nIp, int32_t nPort, int32_t nRewardId);
		void sendNet(EntityPtr& nEntity, ValuePtr& nValue);
				
		NetEngine();
		virtual ~NetEngine();
	};
	
}
