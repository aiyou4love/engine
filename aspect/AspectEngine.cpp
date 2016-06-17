#include "../../Include.hpp"

namespace std {
	
	bool ServiceMgr::runDoing(DoingPtr& nDoing, PlayerPtr& nPlayer, ValuePtr& nValue)
	{
		int32_t serviceId_ = nDoing->getServiceId();
		int32_t doingId_ = nDoing->getDoingId();
		auto it = mServices.find(serviceId_);
		if ( it == mServices.end() ) {
			LOGERROR("[%s]%d", __METHOD__, serviceId_);
			return false;
		}
		IService * service_ = mServices[serviceId_];
		return service_->runDoing(doingId_, nPlayer, nValue);
	}
	
	void ServiceMgr::runRegister(int32_t nId, IService * nService)
	{
		auto it = mServices.find(nId);
		if ( it != mServices.end() ) {
			LOGERROR("[%s]%d", __METHOD__, nId);
			return;
		}
		mServices[nId] = nService;
	}
	
	ServiceMgr& ServiceMgr::instance()
	{
		return mServiceMgr;
	}
	
	ServiceMgr::ServiceMgr()
	{
		mServices.clear();
	}
	
	ServiceMgr::~ServiceMgr()
	{
		mServices.clear();
	}
	ServiceMgr ServiceMgr::mServiceMgr;
	
}
