#pragma once

namespace cc {
	
	class Account : public Entity
	{
	public:
		bool isLogin();
		
		Account();
		~Account();
		
	protected:
		int64_t mAccountId;
	};
	
}
