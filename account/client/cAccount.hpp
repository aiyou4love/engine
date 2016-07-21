#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccount : public Account
	{
	public:
		EdoingState runCondition(DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(DoingPtr& nDoing, ValuePtr& nValue);
		
		const char * getAccountName();
		const char * getAccountPassword();
		int16_t getAccountType();
		
		void runReset();
		
		const char * getRoleName();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runNumber(mAccountName, "mAccountName");
				nSerialize.runNumber(mAccountPassword, "mAccountPassword");
				nSerialize.runNumber(mAccountType, "mAccountType");
				nSerialize.runNumber(mAccountId, "mAccountId");
				nSerialize.runNumber(mServerId, "mServerId");
				nSerialize.runNumber(mRoleId, "mRoleId");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		
		const char * streamName();
		const char * streamUrl();
		
		void runLoad();
		void runSave();
		
		cAccount();
		~cAccount();
		
	protected:
		string mAccountName;
		string mAccountPassword;
		int16_t mAccountType;
	};
	typedef std::shared_ptr<cAccount> cAccountPtr;
#endif

}
