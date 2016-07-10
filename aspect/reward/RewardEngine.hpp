#pragma once

namespace cc {
	
	class RewardEngine : noncopyable
	{
	public:
		void runReward(int32_t nRewardId, EntityPtr& nEntity, ValuePtr& nValue);
		
	public:
		template<class __t>
		void headSerialize(__t& nSerialize, const char * nName)
		{
			nSerialize.runMapStreamPtrs<int32_t, RewardPtr>(mRewards, "rewards", "reward");
		}
		const char * streamName();
		const char * streamUrl();
		
		static RewardEngine& instance();
		
		void runPreinit();
		void runLoad();
		
		RewardEngine();
		~RewardEngine();
		
	private:
		map<int32_t, RewardPtr> mRewards;
		
		static RewardEngine mRewardEngine;
	};
	
}
