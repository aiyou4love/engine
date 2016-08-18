#pragma once

namespace cc {
	
	class ConsoleUpdate : public Context
	{
	public:
		const char * contextName();
		
		void runContext();
	};
	typedef std::shared_ptr<ConsoleUpdate> ConsoleUpdatePtr;
	
}
