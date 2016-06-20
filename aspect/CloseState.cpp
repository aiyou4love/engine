#include "../../Include.hpp"

namespace cc {
	
	void CloseState::pushDoingState(int8_t nDoingId, EdoingState nDoingState)
	{
		mDoingState[nDoingId] = nDoingState;
	}
	
	CloseState::CloseState(int32_t nCloseId)
		: mCloseId (nCloseId)
	{
	}
	
	CloseState::~CloseState()
	{
		mDoingState.clear();
		mCloseId = 0;
	}
	
}
