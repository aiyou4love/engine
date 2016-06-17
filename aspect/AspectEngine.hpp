#pragma once

namespace std {
	
	class ServiceMgr : noncopyable
	{
	public:
		bool runDoing(DoingPtr& nDoing, PlayerPtr& nPlayer, ValuePtr& nValue);
		void runRegister(int32_t nId, IService * nService);
		static ServiceMgr& instance();
		
		ServiceMgr();
		~ServiceMgr();
		
	private:
		map<int32_t, IService *> mServices;
		static ServiceMgr mServiceMgr;
	};
	
}
