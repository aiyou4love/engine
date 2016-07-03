#pragma once

namespace cc {
	
	class SelectState : noncopyable
	{
	public:	
		void pushDoingState(int8_t nDoingId, EdoingState nDoingState);
		
		SelectState(int32_t nSelectId);
		~SelectState();
		
		map<int8_t, EdoingState> mDoingState;
		
	private:
		
		ValuePtr mValue;
		
		int32_t mConditonId;
	};
	typedef boost::shared_ptr<ConditionState> ConditionStatePtr;
	
}
