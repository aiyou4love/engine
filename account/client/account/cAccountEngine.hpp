#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccountEngine : public AccountEngine
	{
	public:
		int8_t runLogin(const char * nName, const char * nPassword, int16_t nAccountType);
		int8_t runRegister(const char * nName, const char * nPassword);
		int8_t isRegister(const char * nValue);
		void runCancel();
		bool isLogin();
		
		string getServerInfo(int16_t nPageId, int16_t nPageCount);
		void setStartServer(int32_t nServerId, int32_t nRoleId);
		string getRoleInfos();
		
		void getAgentInfo(ValuePtr& nValue);
		
		int8_t roleCreate(const char * nRoleName, int16_t nRoleRace);
		
		const char * getRoleName(int32_t nServerId, int32_t nRoleId);
		const char * getServerName(int32_t nServerId);
		EntityPtr& getAccount();
		
		void runPreinit();
		void runLuaApi();
		void runLoad();
		void runClear();
		
		static cAccountEngine& instance();
		
		cAccountEngine();
		~cAccountEngine();
		
	private:
		static cAccountEngine mAccountEngine;
		
		cServerListPtr mServerList;
		cAgentInfoPtr mAgentInfo;
		cRoleListPtr mRoleList;
		
		EntityPtr mAccount;
	};
#endif
	
}
