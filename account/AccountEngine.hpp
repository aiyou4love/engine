#pragma once

namespace cc {
	
	class AccountEngine : noncopyable
	{
	public:				
		AccountEngine& instance();
		
		AccountEngine();
		~AccountEngine();
		
	private:		
		static AccountEngine mAccountEngine;
	};
	
}
