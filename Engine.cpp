#include "Engine.hpp"

void engineStart()
{
	RandomEngine& randomEngine_ = RandomEngine::instance();
	randomEngine_.runPreinit();
	
	ConditionEngine& conditionEngine_ = ConditionEngine::instance();
	conditionEngine_.runPreinit();
	
	RewardEngine& rewardEngine_ = RewardEngine::instance();
	rewardEngine_.runPreinit();
	
	SelectEngine& selectEngine_ = SelectEngine::instance();
	selectEngine_.runPreinit();	
}

void engineStop()
{
}