#pragma once

namespace cc {
	
	class RoleResult : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mErrorCode, "mErrorCode");
			nSerialize.runNumber(mAccountId, "mAccountId");
			nSerialize.runStream(mServerItem, "mServerItem");
			nSerialize.runStream(mRoleItem, "mRoleItem");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		ServerItem& getServerItem();
		RoleItem& getRoleItem();
		int64_t getAccountId();
		int32_t getErrorCode();
		
		RoleResult();
		~RoleResult();
		
	private:
		ServerItem mServerItem;
		RoleItem mRoleItem;
		int64_t mAccountId;
		int32_t mErrorCode;
	};
	typedef std::shared_ptr<RoleResult> RoleResultPtr;
	
}
