#pragma once

namespace cc {
	
	class AccountEngine : public AspectEngine
	{
	public:
		virtual int8_t runLogin(const char * nName, const char * nPassword, int16_t nAccountType);
		virtual int8_t runRegister(const char * nName, const char * nPassword);
		virtual int8_t isRegister(const char * nValue);
		virtual void runCancel();
		
		AccountEngine();
		virtual ~AccountEngine();
	};
	
}
