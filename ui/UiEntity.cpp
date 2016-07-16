#include "../Engine.hpp"

namespace cc {
	
	void UiEntity::runShow()
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.showUi(mName.c_str());
	}
	
	void UiEntity::runRefresh(const char * nEvent)
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.refreshUi(nEvent);
	}
	
	void UiEntity::runClose()
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.closeUi();
	}
	
	UiEntity::UiEntity(const char * nName)
		: mName (nName)
	{
	}
	
	UiEntity::~UiEntity()
	{
		mName = "";
	}
	
}
