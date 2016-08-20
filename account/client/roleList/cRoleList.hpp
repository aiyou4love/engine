#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cRoleList : noncopyable
	{
	public:
		cRoleItemPtr& getRoleItem(int32_t nServerId, int32_t nRoleId);
		
		void pushRoleItems(list<cRoleItemPtr>& nRoleItems);
		void pushRoleItem(cRoleItem& nRoleItem);
		
		map<int64_t, cRoleItemPtr>& getRoleItems();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runMapStreamPtrs<int64_t, cRoleItemPtr>(mRoleItems, "roleItems", "roleItem");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runLoad();
		void runSave();
		
		void runClear();
		
		cRoleList();
		~cRoleList();
		
	private:
		map<int64_t, cRoleItemPtr> mRoleItems;
	};
	typedef SPTR<cRoleList> cRoleListPtr;
#endif
	
}
