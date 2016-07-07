#pragma once

namespace cc {
	
	class Condition : noncopyable
	{
	public:
		int8_t runCondition(EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runMapStreamPtrsCount<int8_t, DoingPtr>(mDoings, "doings", "doing", 10);
			
			nSerialize->runNumber(mConditionId, "conditionId");
		}
		int32_t getKey();
		
		Condition();
		~Condition();
		
	private:
		map<int8_t, DoingPtr> mDoings;
		int32_t mConditionId;
	};
	typedef boost::shared_ptr<Condition> ConditionPtr;
	
}
