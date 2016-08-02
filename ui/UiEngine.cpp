#include "../Engine.hpp"

namespace cc {
	
	void UiEngine::showUi(const char * nName)
	{
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
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.refreshUi(nName, nIndexValue);
	}
	
	void UiEngine::closeUi()
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.closeUi();
	}
	
	void UiEngine::clearUi()
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.clearUi();
	}
	
	UiEngine& UiEngine::instance()
	{
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
