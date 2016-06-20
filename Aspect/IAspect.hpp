#pragma once

namespace cc {
	
	class IAspect : noncopyable
	{
	public:
		virtual EdoingState runCondition(int32_t nCloseId, int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue) = 0;
		virtual void runDoing(int32_t nCloseId, int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue) = 0;
	};
	
}
