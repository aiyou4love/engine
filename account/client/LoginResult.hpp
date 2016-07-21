#pragma once

namespace cc {
	
	class LoginResult : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mAccountId, "mAccountId");
			nSerialize.runStream(mServerItem, "mServerItem");
			nSerialize.runStream(mRoleItem, "mRoleItem");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		ServerItem& getServerItem();
		RoleItem& getRoleItem();
		int64_t getAccountId();
		
		LoginResult();
		~LoginResult();
		
	private:
		ServerItem mServerItem;
		RoleItem mRoleItem;
		int64_t mAccountId;
	};
	typedef std::shared_ptr<LoginResult> LoginResultPtr;
	
}
