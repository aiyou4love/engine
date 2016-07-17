#include "../Engine.hpp"

namespace cc {
	
	int32_t RandomEngine::runRandom(int32_t nMin, int32_t nMax)
	{
		uniform_int_distribution<> distribution_(nMin, nMax);
		return distribution_(mEngine);
	}
	
	void RandomEngine::runPreinit()
	{
		LOGF;
		
		mEngine.seed(mDevice());
	}
	
	RandomEngine& RandomEngine::instance()
	{
		LOGF;
		
		return mRandomEngine;
	}
	
	RandomEngine::RandomEngine()
	{
	}
	
	RandomEngine::~RandomEngine()
	{
	}
	RandomEngine RandomEngine::mRandomEngine;
	
}
