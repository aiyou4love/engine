#pragma once

namespace cc {
	
	class Account : public Entity
	{
	public:
		void setAccountId(int64_t nAccountId);
		void setServerId(int32_t nServerId);
		void setRoleId(int32_t nRoleId);
		
		int64_t getAccountId();
		int32_t getServerId();
		int32_t getRoleId();
		
		virtual const char * getRoleName();
		
		bool isStartRole();
		bool isLogin();
		
		Account();
		virtual ~Account();
		
	protected:
		int64_t mAccountId;
		int16_t mAuthority;
		int32_t mServerId;
		int32_t mRoleId;
	};
	
}
