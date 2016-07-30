#include "../Engine.hpp"

namespace cc {
	
	const char * ConsoleInput::contextName()
	{
		return "consoleInput";
	}
	
	void ConsoleInput::runContext()
	{
		string command_;
		getline(cin, command_);
		
		CommandArgsPtr commandArgs_(new CommandArgs());
		commandArgs_->runParse(command_.c_str());
		
		int8_t flag_ = commandArgs_->getFlag();
		if (1 == flag_) {
			ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
			consoleEngine_.pushCommandArgs(commandArgs_);
		} else if (2 == flag_) {
			
		} else if (3 == flag_) {
			
		} else if (4 == flag_) {
			
		} else {
			
		}
	}
	
}