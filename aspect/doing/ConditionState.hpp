#pragma once

namespace cc {
	
	class ConditionState : noncopyable
	{
	public:	
		void pushDoingState(int8_t nDoingId, EdoingState nDoingState);
		
		ConditionState(int32_t nConditionId);
		~ConditionState();
		
	private:
		map<int8_t, EdoingState> mDoingState;
		
		ValuePtr mValue;
		
		int32_t mConditonId;
	};
	typedef boost::shared_ptr<ConditionState> ConditionStatePtr;
	
}
