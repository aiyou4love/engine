#include "../../Engine.hpp"

namespace cc {
	
	int8_t AccountEngine::runLogin(const char * nName, const char * nPassword, int16_t nAccountType)
	{
		return 0;
	}
	
	int8_t AccountEngine::runRegister(const char * nName, const char * nPassword)
	{
		return 0;
	}
	
	int8_t AccountEngine::isRegister(const char * nValue)
	{
		return 0;
	}
	
	void AccountEngine::runCancel()
	{
	}
	
	bool AccountEngine::isLogin()
	{
		return false;
	}
	
	string AccountEngine::getServerInfo(int16_t nPageId, int16_t nPageCount)
	{
		return "";
	}
	
	void AccountEngine::setStartServer(int32_t nServerId, int32_t nRoleId)
	{
		
	}
	
	string AccountEngine::getEnterValue()
	{
		return "";
	}
	
	string AccountEngine::getRoleInfos()
	{
		return "";
	}
	
	int8_t AccountEngine::roleCreate(const char * nRoleName, int16_t nRoleRace)
	{
		return 0;
	}
	
	const char * AccountEngine::getServerName(int32_t nServerId)
	{
		return "";
	}
	
	void AccountEngine::getAgentInfo(ValuePtr& nValue)
	{
	}
	
	AccountEngine::AccountEngine()
	{
	}
	
	AccountEngine::~AccountEngine()
	{
	}
	
}
