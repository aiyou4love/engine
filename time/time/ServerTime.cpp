#include "../../Engine.hpp"

namespace cc {
	
	void ServerTime::setFirstStart(int64_t nFirstStart)
	{
		mFirstStart = nFirstStart;
	}
	
	int64_t ServerTime::getFirstStart()
	{
		return mFirstStart;
	}
	
	int64_t ServerTime::getStartTime()
	{
		return mStartTime;
	}
	
	void ServerTime::runPreinit()
	{
		time_t ltime_ = time(nullptr);
		tm * tm_ = gmtime(&ltime_);
		time_t gtime_ = mktime(tm_);
		mTimeDiff = (int32_t)(ltime_ - gtime_);
		
		mStartTime = (int64_t)(ltime_);
	}
	
	ServerTime::ServerTime()
		: mFirstStart (0)
		, mStartTime (0)
		, mTimeDiff (0)
	{
	}
	
	ServerTime::~ServerTime()
	{
		mFirstStart = 0;
		mStartTime = 0;
		mTimeDiff = 0;
	}
	
}
