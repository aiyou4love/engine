#include "../Engine.hpp"

namespace cc {
	
	void UiEntity::runShow()
	{
		LOGF;
		
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.showUi(mName.c_str());
	}
	
	void UiEntity::runRefresh(const char * nEvent)
	{
		LOGF;
		
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.refreshUi(nEvent);
	}
	
	void UiEntity::runClose()
	{
		LOGF;
		
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.closeUi();
	}
	
	UiEntity::UiEntity(const char * nName)
		: mName (nName)
	{
		LOGF;
	}
	
	UiEntity::~UiEntity()
	{
		LOGF;
		
		mName = "";
	}
	
}
