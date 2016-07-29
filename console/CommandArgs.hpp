#pragma once

namespace cc {
	
	class CommandArgs : noncopyable
	{
	public:
		const string& getCommandArg(const __i32 nIndex);
		__i32 getCommandCount();
		string& getService();
		string& getFlags();
		
		void runParse(const string& nCommand);
		void runClear();
		
	public:
		CommandArgs();
		~CommandArgs();
		
	private:
		vector<string> mCommandArgs;
		string mService;
		string mFlags;
	};
	
}
