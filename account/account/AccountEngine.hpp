#pragma once

namespace cc {
	
	class AccountEngine : public AspectEngine
	{
	public:
		virtual int8_t runLogin(const char * nName, const char * nPassword, int16_t nAccountType);
		virtual int8_t runRegister(const char * nName, const char * nPassword);
		virtual int8_t isRegister(const char * nValue);
		virtual void runCancel();
		virtual bool isLogin();
		
		virtual string getServerInfo(int16_t nPageId, int16_t nPageCount);
		virtual void setStartServer(int32_t nServerId, int32_t nRoleId);
		virtual string getEnterValue();
		virtual string getRoleInfos();
		
		virtual int8_t roleCreate(const char * nRoleName, int16_t nRoleRace);
		
		virtual const char * getServerName(int32_t nServerId);
		virtual void getAgentInfo(ValuePtr& nValue);
		
		AccountEngine();
		virtual ~AccountEngine();
	};
	
}
