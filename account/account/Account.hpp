#pragma once

namespace cc {
	
	class Account : public Entity
	{
	public:
		void setRoleName(const char * nRoleName);
		void setAccountId(int64_t nAccountId);
		void setServerId(int32_t nServerId);
		void setRoleId(int32_t nRoleId);
		
		void setRoleLevel(int16_t nRoleLevel);
		void setRoleType(int16_t nRoleType);
		void setRoleRace(int16_t nRoleRace);
		void setRoleStep(int16_t nRoleStep);
		
		const char * getRoleName();
		int64_t getAccountId();
		int32_t getServerId();
		int32_t getRoleId();
		
		int16_t getRoleLevel();
		int16_t getRoleType();
		int16_t getRoleRace();
		int16_t getRoleStep();
		
		Account();
		virtual ~Account();
		
	protected:
		int64_t mAccountId;
		int32_t mServerId;
		int32_t mRoleId;
        string mRoleName;
		
        int16_t mRoleType;
        int16_t mRoleRace;
        int16_t mRoleStep;
        int32_t mRoleLevel;
	};
	
}
