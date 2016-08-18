#pragma once

namespace cc {
	
	class ConsoleInput : public Context
	{
	public:
		const char * contextName();
		
		void runContext();
	};
	typedef std::shared_ptr<ConsoleInput> ConsoleInputPtr;
	
}
