#pragma once

namespace cc {
	
	class ConsoleUpdate : public Context
	{
	public:
		const char * contextName();
		
		void runContext();
	};
	typedef SPTR<ConsoleUpdate> ConsoleUpdatePtr;
	
}
