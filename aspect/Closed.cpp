#include "../../Include.hpp"

namespace cc {
	
	void Closed::runDoing(EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine)
	{
		map<int32_t, DoingPtr>::iterator it = mDoings.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			nAspectEngine->runDoing(mId, doing_, nEntity, nValue);
		}
	}
	
	int32_t Closed::getKey()
	{
		return mId;
	}
	
	Closed::Closed()
	{
		mDoings.clear();
		mId = 0;
	}
	
	Closed::~Closed()
	{
		mDoings.clear();
		mId = 0;
	}
	
}
