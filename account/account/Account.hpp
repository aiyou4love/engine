#pragma once

namespace cc {
	
	class Account : public Entity
	{
	public:
		Account();
		virtual ~Account();
		
	protected:
		int64_t mAccountId;
		int16_t mAuthority;
		int32_t mServerId;
		int32_t mRoleId;
	};
	
}
