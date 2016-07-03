#include "../../Include.hpp"

namespace cc {
	
	void ConditionState::pushDoingState(int8_t nDoingId, EdoingState nDoingState)
	{
		mDoingState[nDoingId] = nDoingState;
	}
	
	ConditionState::ConditionState(int32_t nCloseId)
		: mCloseId (nCloseId)
	{
	}
	
	ConditionState::~ConditionState()
	{
		mDoingState.clear();
		mCloseId = 0;
	}
	
}
