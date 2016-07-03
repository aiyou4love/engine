#include "../../Include.hpp"

namespace cc {
	
	void SelectState::pushDoingState(int8_t nDoingId, EdoingState nDoingState)
	{
		mDoingState[nDoingId] = nDoingState;
	}
	
	SelectState::SelectState(int32_t nCloseId)
		: mCloseId (nCloseId)
	{
	}
	
	SelectState::~SelectState()
	{
		mDoingState.clear();
		mCloseId = 0;
	}
	
}
