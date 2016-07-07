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
			nSerialize.runNumber(mAccountId, "accountId");
			nSerialize.runNumber(mServerId, "serverId");
			nSerialize.runNumber(mAccountType, "accountType");
			nSerialize.runNumber(mAccountType, "accountType");
			nSerialize.runNumber(mAccountType, "accountType");
			nSerialize.runNumber(mAccountType, "accountType");
			nSerialize.runNumber(mAccountType, "accountType");
			nSerialize.runNumber(mAccountType, "accountType");
			nSerialize.runNumber(mAccountType, "accountType");
			nSerialize.runNumber(mAccountType, "accountType");
			
			
        int32_t mPlayerId;
        int16_t mPlayerType;
        string mPlayerName;
        int16_t mPlayerRace;
		int16_t mPlayerStep;
        int32_t mPlayerLevel;
		}
		const char * streamName();
		const char * streamUrl();
		
		cAccount();
		~cAccount();
		
	private:
		string mAccountName;
		string mAccountPassword;
		int16_t mAccountType;
	};
	typedef boost::shared_ptr<cAccount> cAccountPtr;
	
}
