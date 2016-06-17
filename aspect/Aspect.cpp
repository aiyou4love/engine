#include "../../Include.hpp"

namespace cc {
	
	void Closed::runCondition(EntityPtr& nEntity, ValuePtr& nValue)
	{
		Aspect& aspect_ = Aspect::instance();
		map<int32_t, DoingPtr>::iterator it = mConditions.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			aspect_.runCondition(doing_, nEntity, nValue);
		}
	}
	
	void Closed::runDoing(EntityPtr& nEntity, ValuePtr& nValue)
	{
		Aspect& aspect_ = Aspect::instance();
		map<int32_t, DoingPtr>::iterator it = mDoings.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			aspect_.runDoing(doing_, nEntity, nValue);
		}
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
