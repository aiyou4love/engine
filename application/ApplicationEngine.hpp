#pragma once

namespace cc {
	
	class ApplicationEngine : noncopyable
	{
	public:
		bool runCondition(DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(DoingPtr& nDoing, ValuePtr& nValue);
		
		ApplicationEngine();
		~ApplicationEngine();
	};
	
}
