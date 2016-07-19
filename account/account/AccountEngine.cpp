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
	
	const char * AccountEngine::getServerName(int32_t nServerId)
	{
		ServerItemPtr serverItem_ = mServerList->getServerItem(nServerId);
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
