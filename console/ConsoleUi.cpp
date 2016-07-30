#include "../Engine.hpp"

namespace cc {
	
	void ConsoleUi::runRefresh(const char * nName, IndexValue& nIndexValue)
	{
		auto it = mOnEvents.find(nName);
		if ( it == mOnEvents.end() ) {
			return;
		}
		mLuaThread->runCall<void, IndexValue *>(nName, &nIndexValue);
	}
	
	bool ConsoleUi::isCommandArgs(CommandArgsPtr& nCommandArgs)
	{
		int16_t itemIndex_ = (int16_t)(nCommandArgs->getSelectId());
		auto it = mConsoleItems.find(itemIndex_);
		if (it == mConsoleItems.end()) {
			LOGE("[%s]%d", __METHOD__, itemIndex_);
			return false;
		}
		ConsoleItemPtr& consoleItem_ = it->second;
		const char * method_ = consoleItem_->getMethod();
		int8_t type_ = consoleItem_->getType();
		if (3 == type_) {
			return true;
		} else if (1 == type_) {
			return mLuaThread->runCall<bool>(method_);
		} else if (2 == type_) {
			int8_t count_ = nCommandArgs->getCommandCount();
			if (count_ > 0) {
				const char * commandArgs_ = nCommandArgs->getCommandArgs(1);
				mLuaThread->runCall<void, const char *>(method_, commandArgs_);
			}
		} else {
			LOGE("[%s]%d", __METHOD__, type_);
		}
		return false;
	}
	
	void ConsoleUi::runCommandArgs(CommandArgsPtr& nCommandArgs)
	{
		int16_t itemIndex_ = (int16_t)(nCommandArgs->getSelectId());
		auto it = mConsoleItems.find(itemIndex_);
		if (it == mConsoleItems.end()) {
			LOGE("[%s]%d", __METHOD__, itemIndex_);
			return;
		}
		ConsoleItemPtr& consoleItem_ = it->second;
		const char * switch_ = consoleItem_->getSwitch();
		int8_t type_ = consoleItem_->getType();
		if (3 == type_) {
			this->runClose();
		} else if (1 == type_) {
			mLuaThread->runCall<void>(switch_);
		} else if (2 == type_) {
			LOGE("[%s]%d", __METHOD__, type_);
		} else {
			LOGE("[%s]%d", __METHOD__, type_);
		}
	}
	
	void ConsoleUi::runText()
	{
		mLuaThread->runCall<void>("showText");
	}
	
	void ConsoleUi::runShow()
	{
		mLuaThread->runCall<void>("runShow");
		
		auto it = mConsoleItems.begin();
		for ( ; it != mConsoleItems.end(); ++it ) {
			ConsoleItemPtr& consoleItem_ = it->second;
			cout << it->first;
			cout << ":) ";
			cout << consoleItem_->getText() << endl;
		}
	}
	
	void ConsoleUi::runClose()
	{
		mLuaThread->runCall<void>("runClose");
		
		mLuaThread->runClose();
		mLuaThread.reset();
		
		mConsoleItems.clear();
		
		mOnEvents.clear();
	}
	
	void ConsoleUi::runInit(const char * nName)
	{
		mName = nName;
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		string uiEventPath_ = workDirectory_.uiEventPath(nName);
		string uiLuaPath_ = workDirectory_.uiLuaPath(nName);
		string uiJsonPath_ = workDirectory_.uiJsonPath(nName);
		this->initEvent(uiEventPath_.c_str());
		this->initUi(uiJsonPath_.c_str());
		this->initLua(uiLuaPath_.c_str());
	}
	
	void ConsoleUi::initEvent(const char * nPath)
	{
		TableReader tableReader_;
		tableReader_.loadFile(nPath);
		tableReader_.selectStream(eventName());
		if ( tableReader_.runChild(eventName())) {
			IoReader<TableReader> ioReader_(tableReader_);
			this->headSerialize(ioReader_, eventName());
		}
	}
	
	void ConsoleUi::initLua(const char * nPath)
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		mLuaThread = luaEngine_.createLuaThread(mName.c_str());
		mLuaThread->openFile(nPath);
		mLuaThread->runCall<void>("runInit");
	}
	
	void ConsoleUi::initUi(const char * nPath)
	{
		TableReader tableReader_;
		tableReader_.loadFile(nPath);
		tableReader_.selectStream(uiName());
		if ( tableReader_.runChild(uiName())) {
			IoReader<TableReader> ioReader_(tableReader_);
			this->headSerialize(ioReader_, uiName());
		}
	}
	
	const char * ConsoleUi::uiName()
	{
		return "consoleUi";
	}
	
	const char * ConsoleUi::uiUrl()
	{
		return "ui.json";
	}
	
	const char * ConsoleUi::eventName()
	{
		return "uiEvent";
	}
	
	const char * ConsoleUi::eventUrl()
	{
		return "event.son";
	}
	
	ConsoleUi::ConsoleUi()
		: mName ("")
	{
	}
	
	ConsoleUi::~ConsoleUi()
	{
		mName = "";
	}
	
}
