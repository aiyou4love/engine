#pragma once

namespace cc {
	
	class cRoleList : noncopyable
	{
	public:
		RoleItemPtr getRoleItem(int32_t nServerId, int32_t nRoleId);
		
		void pushRoleItems(list<RoleItemPtr>& nRoleItems);
		void pushRoleItem(RoleItem& nRoleItem);
		
		map<int64_t, RoleItemPtr>& getRoleItems();
		
		void runClear();
		
		cRoleList();
		~cRoleList();
		
	private:
		map<int64_t, RoleItemPtr> mRoleItems;
	};
	typedef std::shared_ptr<cRoleList> cRoleListPtr;
	
}
