#pragma once

namespace cc {
	
	class AspectEngine : noncopyable
	{
	public:
		bool runCondition(DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(DoingPtr& nDoing, ValuePtr& nValue);
		
		AspectEngine();
		virtual ~AspectEngine();
		
	private:
		map<int32_t, IAspect *> mAspects;
	};
	
}
