#pragma once

namespace cc {
	
	class SelectState : noncopyable
	{
	public:	
		void pushDoingState(int8_t nDoingId, EdoingState nDoingState);
		
		void setIfSelect(int32_t nIfSelectId);
		void setSelect(int32_t nSelectId);
		
		SelectState(int32_t nIfSelectId);
		~SelectState();
		
	private:
		map<int8_t, EdoingState> mDoingState;
		
		int32_t mIfSelectId;
		int32_t mSelectId;
		ValuePtr mValue;
	};
	typedef boost::shared_ptr<SelectState> SelectStatePtr;
	
}
