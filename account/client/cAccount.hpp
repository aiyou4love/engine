#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccount : public Account
	{
	public:
		EdoingState runCondition(DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(DoingPtr& nDoing, ValuePtr& nValue);
		
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
	};
	typedef boost::shared_ptr<cAccount> cAccountPtr;
#endif

}
