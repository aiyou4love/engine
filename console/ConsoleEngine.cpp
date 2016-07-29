#include "../Engine.hpp"

namespace cc {
	
	void ConsoleEngine::showUi(const char * nName)
	{
		this->loadUi(nName);
		this->runRefresh();
	}
	
	void ConsoleEngine::loadUi(const char * nName)
	{
		ConsoleUiPtr consoleUi_(new ConsoleUi());
		consoleUi_->runInit(nName);
		mConsoleUis.push_back(consoleUi_);
	}
	
	void ConsoleEngine::refreshUi(const char * nName, IndexValue& nIndexValue)
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runRefresh(nName, nIndexValue);
		}
		this->runRefresh();
	}
	
	void ConsoleEngine::runRefresh()
	{
		system("cls");
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
		ConsoleUiPtr consoleUi_ = mConsoleUis.back();
		consoleUi_->runClose();
		mConsoleUis.pop_back();
		
		this->runRefresh();
	}
	
	void ConsoleEngine::clearUi()
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runClose();
		}
		mConsoleUis.clear();
	}
	
	void ConsoleEngine::runPreinit()
	{
		system("chcp 65001");
	}
	
	ConsoleEngine& ConsoleEngine::instance()
	{
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
