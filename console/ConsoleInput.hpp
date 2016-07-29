#pragma once

namespace cc {
	
	class ConsoleInput : public Context
	{
	public:
		void runContext();
	};
	typedef std::shared_ptr<ConsoleInput> ConsoleInputPtr;
	
}
