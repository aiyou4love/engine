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
		std::system("cls");
		if (mConsoleUis.empty()) {
			return;
		}
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runText();
		}
		ConsoleUiPtr& consoleUi_ = mConsoleUis.back();
		consoleUi_->runShow();
	}
	
	void ConsoleEngine::closeUi(const char * nName)
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			const char * name_ = consoleUi_->getName();
			if (0 == strcmp(nName, name_)) {
				consoleUi_->runClose();
				mConsoleUis.erase(it);
				break;
			}
		}
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
		this->runRefresh();
	}
	
	void ConsoleEngine::runInit()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		if (!workDirectory_.isConsole()) return;
		
		UiManager& uiManager_ = UiManager::instance();
		uiManager_.registerEngine(this);
		
		ContextPtr consoleInput_(new ConsoleInput());
		ContextPtr consoleUpdate_(new ConsoleUpdate());
		
		HandleEngine& handleEngine_ = HandleEngine::instance();
		handleEngine_.addContext(consoleUpdate_);
		handleEngine_.addContext(consoleInput_);
	}
	
	void ConsoleEngine::runClear()
	{
		this->clearUi();
		
		mCommandArgs.clear();
	}
	
	void ConsoleEngine::pushCommandArgs(CommandArgsPtr& nCommandArgs)
	{
		std::lock_guard<mutex> lock_(mMutex);
		mCommandArgs.push_back(nCommandArgs);
	}
	
	CommandArgsPtr ConsoleEngine::popCommandArgs()
	{
		std::lock_guard<mutex> lock_(mMutex);
		CommandArgsPtr commandArgs_;
		if (mCommandArgs.size() > 0) {
			commandArgs_ = mCommandArgs.front();
			mCommandArgs.pop_front();
		}
		return commandArgs_;
	}
	
	void ConsoleEngine::runCommandArgs()
	{
		if (mConsoleUis.empty()) {
			return;
		}
		CommandArgsPtr commandArgs_ = this->popCommandArgs();
		if (!commandArgs_) {
			return;
		}
		ConsoleUiPtr consoleUi_ = mConsoleUis.back();
		if ( consoleUi_->switchUi(commandArgs_) ) {
			mConsoleUis.pop_back();
			consoleUi_->switchClose(commandArgs_);
			consoleUi_->runClose();
		}
		this->runRefresh();
	}
	
	void ConsoleEngine::runPreinit()
	{
		std::system("chcp 65001");
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tIniting.connect(bind(&ConsoleEngine::runInit, this));
		lifeCycle_.m_tRunClear.connect(bind(&ConsoleEngine::runClear, this));
	}
	
	ConsoleEngine& ConsoleEngine::instance()
	{
		return mConsoleEngine;
	}
	
	ConsoleEngine::ConsoleEngine()
	{
		mConsoleUis.clear();
		mCommandArgs.clear();
	}
	
	ConsoleEngine::~ConsoleEngine()
	{
		mConsoleUis.clear();
		mCommandArgs.clear();
	}
	
	ConsoleEngine ConsoleEngine::mConsoleEngine;
	
}
