#pragma once

namespace cc {
	
	class Reward : noncopyable
	{
	public:
		void runReward(EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runMapStreamPtrsCount<int8_t, DoingPtr>(mDoings, "doings", "doing", 10);
			
			nSerialize->runNumber(mRewardId, "rewardId");
		}
		int32_t getKey();
		
		Reward();
		~Reward();
		
	private:
		map<int8_t, DoingPtr> mDoings;
		int32_t mRewardId;
	};
	typedef std::shared_ptr<Reward> RewardPtr;
	
}
