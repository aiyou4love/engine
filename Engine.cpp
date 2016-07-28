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
	
	UiEngine::instance();
	
	ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
	consoleEngine_.runPreinit();
	
	NetEngine::instance();
	
	IoService& ioService_ = IoService::instance();
	ioService_.runPreinit();
}

void engineStop()
{
	LOGF;
}
