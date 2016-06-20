#pragma once

namespace cc {
	
	class Player : public Entity
	{
	public:
		Player();
		~Player();
		
	private:
		int64_t mAccountId;
		int32_t mPlayerId;
		int32_t mServerId;
		string mPlayerName;
		int16_t mPlayerRace;
	};
	
}
