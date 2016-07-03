#pragma once

namespace cc {
	
	class Selector : noncopyable
	{
	public:
		bool runSelect(EntityPtr& nEntity, ValuePtr& nValue);
		
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
