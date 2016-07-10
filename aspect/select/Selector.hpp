#pragma once

namespace cc {
	
	class Selector : noncopyable
	{
	public:
		bool runSelect(EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mConditionId, "conditionId");
			nSerialize->runNumber(mRewardId, "rewardId");
			nSerialize->runNumber(mSelectId, "selectId");
		}

		bool isDefault();
		int8_t getKey();
		
		Selector();
		~Selector();
		
	private:
		int32_t mConditionId;
		int32_t mRewardId;
		int8_t mSelectId;
	};
	typedef boost::shared_ptr<Selector> SelectorPtr;
	
}
