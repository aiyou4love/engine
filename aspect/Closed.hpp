#pragma once

namespace cc {
	
	class Closed : noncopyable
	{
	public:
		bool runCondition(EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine);
		void runDoing(EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine);
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runMapStreamPtrsCount<int8_t, DoingPtr>(mConditions, "conditions", "condition", 5);
			nSerialize->runMapStreamPtrsCount<int8_t, DoingPtr>(mDoings, "doings", "doing", 5);
			nSerialize->runNumber(mId, "id");
		}
		int32_t getKey();
		
		Closed();
		~Closed();
		
	private:
		map<int8_t, DoingPtr> mConditions;
		map<int8_t, DoingPtr> mDoings;
		int32_t mId;
	};
	typedef shared_ptr<Closed> ClosedPtr;
	
}
