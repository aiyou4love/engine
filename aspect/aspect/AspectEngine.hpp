#pragma once

namespace cc {
	
	class AspectEngine : noncopyable
	{
	public:
		bool runCondition(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue);
		
		void registerAspect(int32_t nAspectId, IAspect * nAspect);
		
		virtual void runClear();
		
		AspectEngine();
		virtual ~AspectEngine();
		
	private:
		map<int32_t, IAspect *> mAspects;
	};
	
}
