#pragma once

namespace cc {
	
	class IAspect : noncopyable
	{
	public:
		virtual bool runCondition(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue) = 0;
		virtual void runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue) = 0;
	};
	
}
