#include "../Engine.hpp"

#include <cstdlib>

namespace cc {
	
	void ConsoleEngine::showUi(const char * nName)
	{
		LOGF;
		this->loadUi(nName);
		this->runRefresh();
	}
	
	void ConsoleEngine::loadUi(const char * nName)
	{
		LOGF;
		ConsoleUiPtr consoleUi_(new ConsoleUi());
		consoleUi_->runInit(nName);
		mConsoleUis.push_back(consoleUi_);
	}
	
	void ConsoleEngine::refreshUi(const char * nName, IndexValue& nIndexValue)
	{
		LOGF;
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runRefresh(nName, nIndexValue);
		}
		this->runRefresh();
	}
	
	void ConsoleEngine::runRefresh()
	{
		//std::system("cls");
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runText();
		}
		ConsoleUiPtr& consoleUi_ = mConsoleUis.back();
		if ( consoleUi_->runShow() ) {
			this->closeUi();
		}
	}
	
	void ConsoleEngine::closeUi()
	{
		LOGF;
		ConsoleUiPtr consoleUi_ = mConsoleUis.back();
		mConsoleUis.pop_back();
		consoleUi_->runClose();
		this->runRefresh();
	}
	
	void ConsoleEngine::clearUi()
	{
		LOGF;
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runClose();
		}
		mConsoleUis.clear();
	}
	
	void ConsoleEngine::runPreinit()
	{
		LOGF;
	}
	
	ConsoleEngine& ConsoleEngine::instance()
	{
		LOGF;
		return mConsoleEngine;
	}
	
	ConsoleEngine::ConsoleEngine()
	{
		mConsoleUis.clear();
	}
	
	ConsoleEngine::~ConsoleEngine()
	{
		mConsoleUis.clear();
	}
	
	ConsoleEngine ConsoleEngine::mConsoleEngine;
	
}
