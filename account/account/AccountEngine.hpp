#pragma once

namespace cc {
	
	class AccountEngine : noncopyable
	{
	public:
		virtual int8_t isRegister(const char * nValue);
		virtual int8_t registerAccount(const char * nName, const char * nPassword);
		virtual int8_t loginAccount(const char * nName, const char * nPassword, int16_t nAccountType);
		virtual void cancelAccount(int64_t nAccountId);
		
		const char * getServerName(int32_t nServerId);
		
		AccountEngine();
		~AccountEngine();
		
	protected:
		ServerListPtr mServerList;
	};
	
}
