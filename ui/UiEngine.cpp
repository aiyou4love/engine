#include "../Engine.hpp"

namespace cc {
	
	void UiEngine::showUi(const char * nName)
	{
		LOGF;
		
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.showUi(nName);
	}
	
	void UiEngine::loadUi(const char * nName)
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.loadUi(nName);
	}
	
	void UiEngine::refreshUi(const char * nName, IndexValue& nIndexValue)
	{
		LOGF;
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.refreshUi(nName, nIndexValue);
	}
	
	void UiEngine::closeUi()
	{
		LOGF;
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.closeUi();
	}
	
	void UiEngine::clearUi()
	{
		LOGF;
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.clearUi();
	}
	
	UiEngine& UiEngine::instance()
	{
		LOGF;
		
		return mUiEngine;
	}
	
	UiEngine::UiEngine()
	{
	}
	
	UiEngine::~UiEngine()
	{
	}
	
	UiEngine UiEngine::mUiEngine;
	
}
