#include "../Engine.hpp"

namespace cc {
	
	const char * ConsoleUpdate::contextName()
	{
		return "consoleUpdate";
	}
	
	void ConsoleUpdate::runContext()
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.runCommandArgs();
	}
	
}
