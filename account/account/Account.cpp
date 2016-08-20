#include "../../Engine.hpp"

namespace cc {
	
	Account::Account()
		: mAccountId (0)
		, mAuthority (0)
		, mServerId (0)
		, mRoleId (0)
	{
	}
	
	Account::~Account()
	{
		mAccountId = 0;
		mAuthority = 0;
		mServerId = 0;
		mRoleId = 0;
	}
	
}
