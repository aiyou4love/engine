#pragma once

namespace cc {
	
	class ConsoleInput : public Context
	{
	public:
		const char * contextName();
		
		void runContext();
	};
	typedef SPTR<ConsoleInput> ConsoleInputPtr;
	
}
