#pragma once

namespace cc {
	
	class Application : public Entity
	{
	public:
		bool runCondition(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue);
		
		Application();
		~Application();
	};
	
}
