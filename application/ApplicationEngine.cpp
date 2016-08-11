#include "../../Engine.hpp"

namespace cc {
	
	bool Application::runCondition(DoingPtr& nDoing, ValuePtr& nValue)
	{
		ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
		return applicationEngine_.runCondition(nDoing, nValue);
	}
	
	void Application::runReward(DoingPtr& nDoing, ValuePtr& nValue)
	{
		ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
		applicationEngine_.runReward(nDoing, nValue);
	}
	
	Application::Application()
	{
	}
	
	Application::~Application()
	{
	}
	
}
