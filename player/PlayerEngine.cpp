#include "../../Include.hpp"

namespace cc {
	
	PlayerEngine& PlayerEngine::instance()
	{
		return mPlayerEngine;
	}
	
	PlayerEngine::PlayerEngine()
	{
	}
	
	PlayerEngine::~PlayerEngine()
	{
	}
	
	PlayerEngine PlayerEngine::mPlayerEngine;
	
}
