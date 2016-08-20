#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccount : public Account
	{
	public:
		bool runCondition(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue);
		
		void initAccountInfo(cLoginResult& nLoginResult);
		
		void setAccountName(const char * nAccountName);
		void setAccountPassword(const char * nPassword);
		void setAccountType(int16_t nAccountType);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mAccountName, "mAccountName");
			nSerialize.runNumber(mAccountPassword, "mAccountPassword");
			nSerialize.runNumber(mAccountType, "mAccountType");
			nSerialize.runNumber(mAccountId, "mAccountId");
			nSerialize.runNumber(mAuthority, "mAuthority");
			nSerialize.runNumber(mServerId, "mServerId");
			nSerialize.runNumber(mRoleId, "mRoleId");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runLoad();
		void runSave();
		
		cAccount();
		~cAccount();
		
	private:
		string mAccountName;
		string mAccountPassword;
		int16_t mAccountType;
	};
	typedef SPTR<cAccount> cAccountPtr;
#endif
	
}
