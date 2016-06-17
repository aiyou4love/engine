#pragma once

namespace std {
	
	class Closed : noncopyable
	{
	public:
		void runCondition(EntityPtr& nEntity, ValuePtr& nValue);
		void runDoing(EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class __t>
		void serialize(__t * nSerialize, int8_t nCount)
		{
			nSerialize->runMapStreamPtrsCount<int32_t, DoingPtr>(mConditions, "conditions", "condition", 5);
			nSerialize->runMapStreamPtrsCount<int32_t, DoingPtr>(mDoings, "doings", "doing", 5);
			nSerialize->runNumber(mId, "id");
		}
		int32_t getKey();
		
		Closed();
		~Closed();
		
	private:
		map<int32_t, DoingPtr> mConditions;
		map<int32_t, DoingPtr> mDoings;
		int32_t mId;
	};
	typedef shared_ptr<Closed> ClosedPtr;
	
}
