#include "../../Include.hpp"

namespace cc {
	
	int32_t Doing::getAspectId()
	{
		return mAspectId;
	}
	
	bool Doing::isDefault()
	{
		return ( (0 == mDoingId) || (0 == mAspectId));
	}
	
	int32_t Doing::getDoingId()
	{
		return mDoingId;
	}
		
	int32_t Doing::getKey()
	{
		return mId;
	}
	
	Doing::Doing()
		: mAspectId (0)
		, mDoingId (0)
		, mId (0)
	{
	}
	
	Doing::~Doing()
	{
		mAspectId = 0;
		mDoingId = 0;
		mId = 0;
	}
	
}
