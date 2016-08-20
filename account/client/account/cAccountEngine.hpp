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
		
		string getServerInfo(int16_t nPageId, int16_t nPageCount);
		void setStartServer(int32_t nServerId, int32_t nRoleId);
		string getStartServerInfo();
		
		const char * getServerName(int32_t nServerId);
		EntityPtr& getAccount();
		
		void runPreInit();
		void runLoad();
		void runClear();
		
		static cAccountEngine& instance();
		
		cAccountEngine();
		~cAccountEngine();
		
	private:
		static cAccountEngine mAccountEngine;
		
		cServerListPtr mServerList;
		cRoleListPtr mRoleList;
		EntityPtr mAccount;
	};
#endif
	
}
