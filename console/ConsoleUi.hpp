#pragma once

namespace cc {
	
	class ConsoleUi : noncopyable
	{
	public:
		void runRefresh(const char * nName, IndexValue& nIndexValue);
		
		bool isCommandArgs(CommandArgsPtr& nCommandArgs);
		void runCommandArgs(CommandArgsPtr& nCommandArgs);
				
		void runClose();
		
		void runInit(const char * nName);
		
		void runText();
		void runShow();
		
	private:
		void initEvent(const char * nPath);
		void initLua(const char * nPath);
		void initUi(const char * nPath);
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(eventName(), nName) ) {
				nSerialize.runNumbers<string>(mOnEvents, "onEvents", "onEvent");
			} else if ( 0 == strcmp(uiName(), nName) ) {
				nSerialize.runMapStreamPtrs<int16_t, ConsoleItemPtr>(mConsoleItems, "consoleItems", "consoleItem");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * uiName();
		const char * uiUrl();
		
		const char * eventName();
		const char * eventUrl();
		
		ConsoleUi();
		~ConsoleUi();
		
	private:
		map<int16_t, ConsoleItemPtr> mConsoleItems;
		
		set<string> mOnEvents;
		LuaThreadPtr mLuaThread;
		string mName;
	};
	typedef std::shared_ptr<ConsoleUi> ConsoleUiPtr;
	
}
