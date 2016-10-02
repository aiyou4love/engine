#include "Engine.hpp"

using namespace cc;

void engineStart()
{
	TimeEngine& timeEngine_ = TimeEngine::instance();
	timeEngine_.runPreinit();
	
	cServerTime& serverTime_ = cServerTime::instance();
	serverTime_.runPreinit();
	
#ifdef __CLIENT__
	RoleEngine& roleEngine_ = RoleEngine::instance();
	roleEngine_.runPreinit();
#endif

	cAccountEngine& accountEngine_ = cAccountEngine::instance();
	accountEngine_.runPreinit();
}
