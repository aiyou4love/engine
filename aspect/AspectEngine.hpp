#pragma once

namespace cc {
	
	class AspectEngine : noncopyable
	{
	public:
		EdoingState runCondition(int32_t nCloseId, DoingPtr& nDoing, EntityPtr& nEntity, ValuePtr& nValue);
		void runDoing(int32_t nCloseId, DoingPtr& nDoing, EntityPtr& nEntity, ValuePtr& nValue);
		
		void runRegister(int32_t nId, IAspect * nAspect);
		
		AspectEngine();
		~AspectEngine();
		
	private:
		map<int32_t, IAspect *> mAspects;
	};
	
}
