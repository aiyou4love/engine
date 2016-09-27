#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class RoleEngine : noncopyable
	{
	public:
		int8_t runRoleList(int64_t nAccountId);
		
		void pushRoleItem(RoleItemPtr& nRoleItem);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runMapStreamPtrs<int64_t, RoleItemPtr>(mRoleItems, "roleItems", "roleItem");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runSave();
		void runClear();
		
		static RoleEngine& instance();
		
		RoleEngine();
		~RoleEngine();
		
	private:
		map<int64_t, RoleItemPtr> mRoleItems;
		
		static RoleEngine mRoleEngine;
	};
#endif
	
}
