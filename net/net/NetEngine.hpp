#pragma once

namespace cc {
	
	class NetEngine : noncopyable
	{
	public:
		virtual void initNet(EntityPtr& nEntity, const char * nIp, const char * nPort, int32_t nConnectId, int32_t nDisconnectId);
		void sendNet(EntityPtr& nEntity, ValuePtr& nValue);
		
		NetEngine();
		virtual ~NetEngine();
	};
	
}
