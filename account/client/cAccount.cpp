#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	cAccount::cAccount()
		: mAccountName ("")
		, mAccountPassword ("")
		, mAccountType (0)
		, mAccountId (0)
	{
	}
	
	cAccount::~cAccount()
	{
		mAccountName = "";
		mAccountPassword = "";
		mAccountType = 0;
		mAccountId = 0;
	}
#endif

}
