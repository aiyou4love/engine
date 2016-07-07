#include "../../Engine.hpp"

namespace cc {
	
	void SelectState::pushDoingState(int8_t nDoingId, EdoingState nDoingState)
	{
		mDoingState[nDoingId] = nDoingState;
	}
	
	void SelectState::setIfSelect(int32_t nIfSelectId)
	{
		mIfSelectId = nIfSelectId;
	}
	
	void SelectState::setSelect(int32_t nSelectId)
	{
		mSelectId = nSelectId;
	}
	
	SelectState::SelectState(int32_t nIfSelectId)
		: mIfSelectId (nIfSelectId)
		, mSelectId (0)
	{
		mDoingState.clear();
	}
	
	SelectState::~SelectState()
	{
		mDoingState.clear();
		mIfSelectId = 0;
		mSelectId = 0;
	}
	
}
