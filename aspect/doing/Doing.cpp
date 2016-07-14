#include "../../Engine.hpp"

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
	
	int8_t Doing::getKey()
	{
		return mIndex;
	}
	
	Doing::Doing()
		: mAspectId (0)
		, mDoingId (0)
		, mIndex (0)
	{
	}
	
	Doing::~Doing()
	{
		mAspectId = 0;
		mDoingId = 0;
		mIndex = 0;
	}
	
}
