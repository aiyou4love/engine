#pragma once

namespace cc {
	
	class PlayerRandom : public IAspect
	{
	public:
		EdoingState runCondition(int32_t nCloseId, int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		void runDoing(int32_t nCloseId, int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
	};
	
}
