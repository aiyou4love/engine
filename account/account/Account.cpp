#include "../../Engine.hpp"

namespace cc {
	
	bool Account::isLogin()
	{
		return (mAccountId > 0);
	}
	
	Account::Account()
		: mAccountId (0)
	{
	}
	
	Account::~Account()
	{
		mAccountId = 0;
	}
	
}
