#pragma once

namespace cc {
	
	class cRoleList : noncopyable
	{
	public:
		RoleItemPtr& getRoleItem(int32_t nServerId, int32_t nRoleId);
		
		void pushRoleItems(list<RoleItemPtr>& nRoleItems);
		void pushRoleItem(RoleItem& nRoleItem);
		
		map<int64_t, RoleItemPtr>& getRoleItems();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int64_t, RoleItemPtr>(mRoleItems, "roleItems", "roleItem");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		void runLoad();
		void runSave();
		
		void runClear();
		
		cRoleList();
		~cRoleList();
		
	private:
		map<int64_t, RoleItemPtr> mRoleItems;
	};
	typedef std::shared_ptr<cRoleList> cRoleListPtr;
	
}
