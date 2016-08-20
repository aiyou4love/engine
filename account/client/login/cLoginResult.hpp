#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cLoginResult : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mAccountId, "mAccountId");
			nSerialize.runNumber(mAuthority, "mAuthority");
			nSerialize.runStream(mServerItem, "mServerItem");
			nSerialize.runStream(mRoleItem, "mRoleItem");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		cServerItem& getServerItem();
		cRoleItem& getRoleItem();
		int64_t getAccountId();
		int16_t getAuthority();
		
		cLoginResult();
		~cLoginResult();
		
	private:
		cServerItem mServerItem;
		cRoleItem mRoleItem;
		int64_t mAccountId;
		int16_t mAuthority;
	};
	typedef SPTR<cLoginResult> cLoginResultPtr;
#endif
	
}
