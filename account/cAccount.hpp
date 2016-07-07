#pragma once

namespace cc {
	
	class cAccount : public Account
	{
	public:
		EdoingState runCondition(DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(DoingPtr& nDoing, ValuePtr& nValue);
		
		template<class __t>
		void headSerialize(__t& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mAccountName, "accountName");
			nSerialize.runNumber(mAccountPassword, "accountPassword");
			nSerialize.runNumber(mAccountType, "accountType");
		}
		const char * streamName();
		const char * streamUrl();
		
		cAccount();
		~cAccount();
		
	private:
		string mAccountName;
		string mAccountPassword;
		int16_t mAccountType;
		bool mIsLoad;
	};
	typedef boost::shared_ptr<cAccount> cAccountPtr;
	
}
