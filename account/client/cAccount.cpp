#include "../../Engine.hpp"

namespace cc {
	
	Account::Account()
		: mAccountName ("")
		, mAccountPassword ("")
		, mAccountType (0)
		, mAccountId (0)
	{
	}
	
	Account::~Account()
	{
		mAccountName = "";
		mAccountPassword = "";
		mAccountType = 0;
		mAccountId = 0;
	}
	
}
