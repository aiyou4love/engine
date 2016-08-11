#pragma once

namespace cc {
	
	class Application : public Entity
	{
	public:
		bool runCondition(DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(DoingPtr& nDoing, ValuePtr& nValue);
		
		Application();
		~Application();
	};
	
}
