#include "../../Include.hpp"

namespace cc {
		
	Player::Player()
		: mAccountId (0)
		, mPlayerId (0)
		, mServerId (0)
		, mPlayerName ("")
		, mPlayerRace (0)
	{
	}
	
	Player::~Player()
	{
		mAccountId = 0;
		mPlayerId = 0;
		mServerId = 0;
		mPlayerName = "";
		mPlayerRace = 0;
	}
	
}
