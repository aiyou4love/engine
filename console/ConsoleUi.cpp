#include "../Engine.hpp"

namespace cc {
	
	void ConsoleUi::runRefresh(const char * nName, IndexValue& nIndexValue)
	{
		LOGF;
		auto it = mOnEvents.find(nName);
		if ( it == mOnEvents.end() ) {
			return;
		}
		mLuaThread->runCall<void, IndexValue *>(nName, &nIndexValue);
	}
	
	void ConsoleUi::runClose()
	{
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
		mLuaThread->runCall("runInit");
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
	
	void ConsoleUi::runText()
	{
		mLuaThread->runCall("showText");
	}
	
	bool ConsoleUi::runShow()
	{
		mLuaThread->runCall("runShow");
		
		bool needCin_ = false;
		auto it = mConsoleItems.begin();
		for ( ; it != mConsoleItems.end(); ++it ) {
			ConsoleItemPtr& consoleItem_ = it->second;
			if ( 1 == consoleItem_->getType() ) {
				cout << it->first;
				cout << ":) ";
				cout << consoleItem_->getText() << endl;
				needCin_ = true;
			}
		}
		int16_t itemIndex_ = 0;
		it = mConsoleItems.begin();
		for ( ; it != mConsoleItems.end(); ++it ) {
			ConsoleItemPtr& consoleItem_ = it->second;
			if ( 2 == consoleItem_->getType() ) {
				const char * name_ = consoleItem_->getName();
				if ( !mLuaThread->runCall<bool, const char *>("needShow", name_) ) {
					continue;
				}
				cout << consoleItem_->getText();
				cout << ":) ";
				while(true) {
					string value_;
					cin >> value_;
					int16_t index_ = this->getItemIndex(value_);
					if (-1 == index_) {
						cout << "error! please reinput:) ";
						continue;
					}
					if (index_ > 0) {
						itemIndex_ = index_;
						break;
					}
					const char * method_ = consoleItem_->getMethod();
					if (mLuaThread->runCall<bool, string&>(method_, value_)) {
						break;
					}
				}
				if (itemIndex_ > 0) {
					break;
				}
			}
		}
		if (itemIndex_ <= 0) {
			while (needCin_) {
				string value_;
				cin >> value_;
				int16_t index_ = this->getItemIndex(value_);
				if (index_ > 0) {
					itemIndex_ = index_;
					break;
				} else {
					cout << "error! please reinput:) ";
					continue;
				}
			}
		}
		if (itemIndex_ > 0) {
			return this->runItemIndex(itemIndex_);
		}
		return false;
	}
	
	int16_t ConsoleUi::getItemIndex(string& nText)
	{
		if ( nText.length() <= 0 ) {
			return -1;
		}
		if ('#' == nText[0]) {
			if ( nText.length() < 2 ) {
				return -1;
			}
			string value_ = nText.substr(1);
			for (size_t i = 0; i < value_.length(); ++i) {
				if (!isdigit(value_[i])) {
					return -1;
				}
			}
			int16_t result_ = convertValue<string, int16_t>(value_);
			auto it = mConsoleItems.find(result_);
			if (it == mConsoleItems.end()) {
				return -1;
			}
			return result_;
		}
		return 0;
	}
	
	bool ConsoleUi::runItemIndex(int16_t nItemIndex)
	{
		auto it = mConsoleItems.find(nItemIndex);
		if (it == mConsoleItems.end()) {
			LOGE("[%s]%d", __METHOD__, nItemIndex);
			return true;
		}
		ConsoleItemPtr& consoleItem_ = it->second;
		const char * method_ = consoleItem_->getMethod();
		return mLuaThread->runCall<bool>(method_);
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
		LOGF;
	}
	
	ConsoleUi::~ConsoleUi()
	{
		LOGF;
		mName = "";
	}
	
}
