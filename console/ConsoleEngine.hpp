#pragma once

namespace cc {
	
	class ConsoleEngine : noncopyable
	{
	public:
		void showUi(const char * nName);
		void refreshUi(const char * nEvent);
		void closeUi();
		
		template<class __t>
		void headSerialize(__t& nSerialize, const char * nName)
		{
			nSerialize.runMapStreamPtrs<int16_t, ConsoleItemPtr>(mConsoleItems, "consoleItems", "consoleItem");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		
		static ConsoleEngine& instance();
		
		ConsoleEngine();
		~ConsoleEngine();
		
	private:
		map<int16_t, ConsoleItemPtr> mConsoleItems;
		
		LuaThreadPtr mLuaThread;
		
		static ConsoleEngine mConsoleEngine;
	};
	
}
