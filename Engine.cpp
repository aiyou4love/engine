#include "Engine.hpp"

using namespace cc;

void engineStart()
{
	LOGF;
	
	RandomEngine& randomEngine_ = RandomEngine::instance();
	randomEngine_.runPreinit();
	
	ConditionEngine& conditionEngine_ = ConditionEngine::instance();
	conditionEngine_.runPreinit();
	
	RewardEngine& rewardEngine_ = RewardEngine::instance();
	rewardEngine_.runPreinit();
	
	SelectEngine& selectEngine_ = SelectEngine::instance();
	selectEngine_.runPreinit();
	
	cAccountEngine& accountEngine_ = cAccountEngine::instance();
	accountEngine_.runPreinit();
	
	UiEngine& uiEngine_ = UiEngine::instance();
	uiEngine_.runPreinit();
	
	ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
	consoleEngine_.runPreinit();
}

void engineStop()
{
	LOGF;
}
