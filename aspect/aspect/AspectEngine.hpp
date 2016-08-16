#pragma once

namespace cc {
	
	class AspectEngine : noncopyable
	{
	public:
		void registerAspect(int32_t nAspectId, IAspect * nAspect);
		
		bool runCondition(DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(DoingPtr& nDoing, ValuePtr& nValue);
		
		virtual void runClear();
		
		AspectEngine();
		virtual ~AspectEngine();
		
	private:
		map<int32_t, IAspect *> mAspects;
	};
	
}
