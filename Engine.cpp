#include "Engine.hpp"

using namespace cc;

void engineStart()
{
	TimeEngine& timeEngine_ = TimeEngine::instance();
	timeEngine_.runPreinit();
	
	cServerTime& serverTime_ = cServerTime::instance();
	serverTime_.runPreinit();
}
