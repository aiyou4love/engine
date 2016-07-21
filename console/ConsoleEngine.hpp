#pragma once

namespace cc {
	
	class ConsoleEngine : noncopyable
	{
	public:
		void showUi(const char * nName);
		void loadUi(const char * nName);
		void refreshUi(const char * nName, IndexValue& nIndexValue);
		void closeUi();
		void clearUi();
		
	private:
		void runRefresh();
		
	public:
		void runPreinit();
		
		static ConsoleEngine& instance();
		
		ConsoleEngine();
		~ConsoleEngine();
		
	private:
		deque<ConsoleUiPtr> mConsoleUis;
		
		static ConsoleEngine mConsoleEngine;
	};
	
}
