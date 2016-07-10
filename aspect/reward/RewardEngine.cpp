#include "../../Engine.hpp"

namespace cc {
	
	void RewardEngine::runReward(int32_t nRewardId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mRewards.find(nRewardId);
		if ( it == mRewards.end() ) {
			LOGERROR("[%s]%d", __METHOD__, nRewardId);
			return;
		}
		RewardPtr& reward_ = it->second;
		reward_->runReward(nEntity, nValue);
	}
	
	void RewardEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&RewardEngine::runLoad, this));
	}
	
	void RewardEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runTable<RewardEngine *>(this, streamUrl(), streamName());
	}
	
	const char * RewardEngine::streamName()
	{
		return "rewardEngine";
	}
	
	const char * RewardEngine::streamUrl()
	{
		return "arc://rewardEngine.json";
	}
	
	RewardEngine& RewardEngine::instance()
	{
		return mRewardEngine;
	}
	
	RewardEngine::RewardEngine()
	{
		mRewards.clear();
	}
	
	RewardEngine::~RewardEngine()
	{
		mRewards.clear();
	}
	
	RewardEngine RewardEngine::mRewardEngine;
	
}
