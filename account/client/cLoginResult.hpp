#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cLoginResult : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runStreamPtr(mRoleItem, "mRoleItem");
			nSerialize.runNumber(mAccountId, "mAccountId");
			nSerialize.runNumber(mAuthority, "mAuthority");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		RoleItemPtr& getRoleItem();
		int64_t getAccountId();
		int16_t getAuthority();
		
		cLoginResult();
		~cLoginResult();
		
	private:
		RoleItemPtr mRoleItem;
		int64_t mAccountId;
		int16_t mAuthority;
	};
	typedef SPTR<cLoginResult> cLoginResultPtr;
#endif
	
}
