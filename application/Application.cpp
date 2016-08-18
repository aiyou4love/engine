#include "../../Engine.hpp"

namespace cc {
	
	bool Application::runCondition(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue)
	{
		ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
		return applicationEngine_.runCondition(nEntity, nDoing, nValue);
	}
	
	void Application::runReward(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue)
	{
		ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
		applicationEngine_.runReward(nEntity, nDoing, nValue);
	}
	
	Application::Application()
	{
	}
	
	Application::~Application()
	{
	}
	
}
