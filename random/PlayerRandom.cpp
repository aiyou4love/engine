#include "../Engine.hpp"

namespace cc {
	
	EdoingState PlayerRandom::runCondition(int32_t nCloseId, int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		return EdoingState::mTrue;
	}
	
	void PlayerRandom::runDoing(int32_t nCloseId, int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
	}
	
}
