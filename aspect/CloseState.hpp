#pragma once

namespace cc {
	
	class CloseState : noncopyable
	{
	public:	
		CloseState();
		~CloseState();
		
	private:
		map<int8_t, EdoingState> mDoingState;
		
		ValuePtr mResult;
		ValuePtr mValue;
		
		int32_t mCloseId;
	};
	typedef shared_ptr<CloseState> CloseStatePtr;
	
}
