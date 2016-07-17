#pragma once

namespace cc {
	
	class AccountEngine : noncopyable
	{
	public:
		virtual int8_t isRegister(const char * nValue);
		
		AccountEngine();
		~AccountEngine();
	};
	
}
