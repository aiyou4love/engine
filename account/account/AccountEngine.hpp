#pragma once

namespace cc {
	
	class AccountEngine : noncopyable
	{
	public:
		virtual int8_t isRegister(const char * nValue);
		virtual int8_t registerAccount(const char * nName, const char * nPassword);
		virtual int8_t loginAccount(const char * nName, const char * nPassword, int16_t nAccountType);
		virtual void cancelAccount(int64_t nAccountId);
		virtual int8_t getAgentServer(ValuePtr& nValue);
		virtual string startServers();
		virtual string pageServers(int16_t nPageId, int16_t nPageCount);
		virtual void selectServer(int32_t nServerId, int32_t nRoleId);
		virtual int8_t roleCreate(const char * nRoleName, int16_t nRoleRace);
		
		const char * getServerName(int32_t nServerId);
		
		AccountEngine();
		virtual ~AccountEngine();
		
	protected:
		ServerListPtr mServerList;
	};
	
}
