#include "../../Engine.hpp"

namespace cc {
	
#ifndef __CLIENT__
	int64_t cServerTime::getServerTime()
	{
		return (int64_t)(time(nullptr));
	}
	
	cServerTime& cServerTime::instance()
	{
		return mServerTime;
	}
	
	cServerTime::cServerTime()
	{
	}
	
	cServerTime::~cServerTime()
	{
	}
	
	cServerTime cServerTime::mServerTime;
#endif
	
}
