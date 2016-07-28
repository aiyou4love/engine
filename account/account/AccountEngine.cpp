#include "../../Engine.hpp"

namespace cc {
	
	int8_t AccountEngine::isRegister(const char * nValue)
	{
		return 0;
	}
	
	int8_t AccountEngine::registerAccount(const char * nName, const char * nPassword)
	{
		return 0;
	}
	
	int8_t AccountEngine::loginAccount(const char * nName, const char * nPassword, int16_t nAccountType)
	{
		return 0;
	}
	
	void AccountEngine::cancelAccount(int64_t nAccountId)
	{
		
	}
	
	int8_t AccountEngine::accountEnter()
	{
		return 0;
	}
	
	string AccountEngine::startServers()
	{
		return "";
	}
	
	string AccountEngine::pageServers(int16_t nPageId, int16_t nPageCount)
	{
		return "";
	}
	
	void AccountEngine::selectServer(int32_t nServerId, int32_t nRoleId)
	{
		
	}
	
	int8_t AccountEngine::roleCreate(const char * nRoleName, int16_t nRoleRace)
	{
		return 0;
	}
	
	const char * AccountEngine::getServerName(int32_t nServerId)
	{
		ServerItemPtr& serverItem_ = mServerList->getServerItem(nServerId);
		return serverItem_->getServerName();
	}
	
	AccountEngine::AccountEngine()
		: mServerList (new ServerList())
	{
	}
	
	AccountEngine::~AccountEngine()
	{
		mServerList.reset();
	}
	
}
