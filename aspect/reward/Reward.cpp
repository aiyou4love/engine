#include "../../Engine.hpp"

namespace cc {
	
	void Reward::runReward(EntityPtr& nEntity, ValuePtr& nValue)
	{
		LOGF;
		
		auto it = mDoings.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			nEntity->runReward(doing_, nValue);
		}
	}
	
	int32_t Reward::getKey()
	{
		return mRewardId;
	}
	
	Reward::Reward()
		: mRewardId (0)
	{
		mDoings.clear();
	}
	
	Reward::~Reward()
	{
		mRewardId = 0;
		
		mDoings.clear();
	}
	
}
