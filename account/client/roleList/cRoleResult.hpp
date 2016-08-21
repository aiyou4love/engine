#pragma once

namespace cc {
	
	class cRoleResult : noncopyable
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
		
		cServerItem& getServerItem();
		cRoleItem& getRoleItem();
		int64_t getAccountId();
		int32_t getErrorCode();
		
		cRoleResult();
		~cRoleResult();
		
	private:
		cServerItem mServerItem;
		cRoleItem mRoleItem;
		int64_t mAccountId;
		int32_t mErrorCode;
	};
	typedef std::shared_ptr<cRoleResult> cRoleResultPtr;
	
}
