#pragma once

namespace cc {
	
	class cAccount : public Account
	{
	public:
		template<class T>
		void serialize(T nSerialize, const char * nName)
		{
			nSerialize->runNumber(mAccountName, "mAccountName");
			nSerialize->runNumber(mAccountPassword, "mAccountPassword");
			nSerialize->runNumber(mAccountType, "mAccountType");
			nSerialize->runNumber(mAccountId, "mAccountId");
		}
		
		cAccount();
		~cAccount();
		
	protected:
		string mAccountName;
		string mAccountPassword;
		int16_t mAccountType;
		int64_t mAccountId;
	};
	
}
