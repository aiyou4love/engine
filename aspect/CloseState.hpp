#pragma once

namespace cc {
	
	class CloseState : noncopyable
	{
	public:	
		void pushDoingState(int8_t nDoingId, EdoingState nDoingState);
		
		CloseState(int32_t nCloseId);
		~CloseState();
		
	private:
		map<int8_t, EdoingState> mDoingState;
		
		ValuePtr mValue;
		
		int32_t mCloseId;
	};
	typedef shared_ptr<CloseState> CloseStatePtr;
	
}
