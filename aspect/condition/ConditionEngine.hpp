#pragma once

namespace cc {
	
	class ConditionEngine : noncopyable
	{
	public:
		int8_t runCondition(int32_t nConditionId, EntityPtr& nEntity, ValuePtr& nValue)
		
	public:
		template<class __t>
		void headSerialize(__t& nSerialize)
		{
			nSerialize.runMapStreamPtrs<int32_t, ConditionPtr>(mConditions, "conditions", "condition");
		}
		const char * streamName();
		const char * streamUrl();
		
		ConditionEngine& instance();
		
		void runPreinit();
		void runLoad();
		
		ConditionEngine();
		~ConditionEngine();
		
	private:
		map<int32_t, ConditionPtr> mConditions;
		
		static ConditionEngine mConditionEngine;
	};
	
}
