#include "../../Include.hpp"

namespace std {
	
	bool Closed::runDoing(PlayerPtr& nPlayer, ValuePtr& nValue)
	{
		ServiceMgr& serviceMgr_ = ServiceMgr::instance();
		map<int32_t, DoingPtr>::iterator it = mDoings.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			if ( !serviceMgr_.runDoing(doing_, nPlayer, nValue) ) {
				return false;
			}
		}
		return true;
	}
	
	int32_t Closed::getKey()
	{
		return mId;
	}
	
	Closed::Closed()
	{
		mConditions.clear();
		mDoings.clear();
		mId = 0;
	}
	
	Closed::~Closed()
	{
		mConditions.clear();
		mDoings.clear();
		mId = 0;
	}
	
}
