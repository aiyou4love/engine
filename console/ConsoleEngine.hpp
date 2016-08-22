#pragma once

namespace cc {
	
	class ConsoleEngine : public IUiEngine
	{
	public:
		void showUi(const char * nName);
		void loadUi(const char * nName);
		
		void refreshUi(const char * nName, IndexValue& nIndexValue);
		
		void closeUi(const char * nName);
		void clearUi();
		
		void runClear();
		
		void pushCommandArgs(CommandArgsPtr& nCommandArgs);
		CommandArgsPtr popCommandArgs();
		
		void runCommandArgs();
		
	private:
		void runRefresh();
		
	public:
		void runPreinit();
		void runLuaApi();
		void runInit();
		
		static ConsoleEngine& instance();
		
		ConsoleEngine();
		~ConsoleEngine();
		
	private:
		deque<ConsoleUiPtr> mConsoleUis;
		
		deque<CommandArgsPtr> mCommandArgs;
		mutex mMutex;
		
		static ConsoleEngine mConsoleEngine;
	};
	
}
