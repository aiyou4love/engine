#pragma once

namespace cc {
	
	class Account : public Entity
	{
	public:
		Account();
		~Account();
		
	protected:
		int64_t mAccountId;
		int32_t mServerId;
        int32_t mPlayerId;
        int16_t mPlayerType;
        string mPlayerName;
        int16_t mPlayerRace;
		int16_t mPlayerStep;
        int32_t mPlayerLevel;
	};
	
}
