#pragma once

namespace cc {
	
	class Closed : noncopyable
	{
	public:
		template <class P, class A>
		int16_t runCondition(P& nP, ValuePtr& nValue)
		{
			int16_t result_ = 0;
			A& aspect_ = A::instance();
			map<int32_t, DoingPtr>::iterator it = mConditions.begin();
			for ( ; it != mDoings.end(); ++it ) {
				DoingPtr& doing_ = it->second;
				result_ += aspect_.runCondition(mId, doing_, nP, nValue);
			}
			return result_;
		}
		
		template <class P, class A>
		void runDoing(P& nP, ValuePtr& nValue)
		{
			A& aspect_ = A::instance();
			map<int32_t, DoingPtr>::iterator it = mDoings.begin();
			for ( ; it != mDoings.end(); ++it ) {
				DoingPtr& doing_ = it->second;
				aspect_.runDoing(doing_, nP, nValue);
			}
		}
		
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
