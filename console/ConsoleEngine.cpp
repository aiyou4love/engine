#include "../Engine.hpp"

namespace cc {
	
	void ConsoleEngine::showUi(const char * nName)
	{
		LOGF;
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		string uiLuaPath_ = workDirectory_.uiLuaPath(nName);
		string uiJsonPath_ = workDirectory_.uiJsonPath(nName);
		
		TableReader tableReader_;
		tableReader_.loadFile(uiJsonPath_.c_str());
		tableReader_.selectStream(streamName());
		if ( tableReader_.runChild(streamName())) {
			IoReader<TableReader> ioReader_(tableReader_);
			this->headSerialize(ioReader_, streamName());
		}
		
		LuaEngine& luaEngine_ = LuaEngine::instance();
		mLuaThread = luaEngine_.createLuaThread(nName);
		mLuaThread->openFile(uiLuaPath_.c_str());
		
		auto it = mConsoleItems.begin();
		for ( ; it != mConsoleItems.end(); ++it ) {
			ConsoleItemPtr& consoleItem_ = it->second;
			if (!consoleItem_->isGlob()) {
				continue;
			}
			cout << endl << it->first;
			cout << ":) ";
			cout << consoleItem_->getText() << endl;
		}
		it = mConsoleItems.begin();
		for ( ; it != mConsoleItems.end(); ++it ) {
			ConsoleItemPtr& consoleItem_ = it->second;
			if (consoleItem_->isGlob()) {
				continue;
			}
			cout << consoleItem_->getText() << endl;
			cout << ":) ";
			string value_;
			cin >> value_;
			
		}
	}
	
	void ConsoleEngine::refreshUi(const char * nEvent)
	{
		LOGF;
		
		mLuaThread->runCall(nEvent);
	}
	
	void ConsoleEngine::closeUi()
	{
		LOGF;
		
		mLuaThread->runClose();
		mLuaThread.reset();
		
		mConsoleItems.clear();
	}
	
	const char * ConsoleEngine::streamName()
	{
		return "consoleEngine";
	}
	
	const char * ConsoleEngine::streamUrl()
	{
		return "consoleEngine.json";
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
		mConsoleItems.clear();
	}
	
	ConsoleEngine::~ConsoleEngine()
	{		
		mConsoleItems.clear();
	}
	
	ConsoleEngine ConsoleEngine::mConsoleEngine;
	
}
