#include "Engine.hpp"

using namespace cc;

void engineStart()
{
	ConditionEngine& conditionEngine_ = ConditionEngine::instance();
	conditionEngine_.runPreinit();
	
	RewardEngine& rewardEngine_ = RewardEngine::instance();
	rewardEngine_.runPreinit();
	
	SelectEngine& selectEngine_ = SelectEngine::instance();
	selectEngine_.runPreinit();
	
	IoService& ioService_ = IoService::instance();
	ioService_.runPreinit();
	
	ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
	applicationEngine_.runPreinit();
	
	ConnectSession& connectSession_ = ConnectSession::instance();
	connectSession_.runPreinit();
	
	ConnectEngine& connectEngine_ = ConnectEngine::instance();
	connectEngine_.runPreinit();
	
	SessionMgr& sessionMgr_ = SessionMgr::instance();
	sessionMgr_.runPreinit();
	
	AcceptEngine& acceptEngine_ = AcceptEngine::instance();
	acceptEngine_.runPreinit();
	
	UiManager::instance();
	
	ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
	consoleEngine_.runPreinit();
	
	cAccountEngine& accountEngine_ = cAccountEngine::instance();
	accountEngine_.runPreinit();
}
