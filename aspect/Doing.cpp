#include "../../Include.hpp"

namespace std {
	
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
		: mServiceId (0)
		, mDoingId (0)
		, mId (0)
	{
		
	}
	
	Doing::~Doing()
	{
		mServiceId = 0;
		mDoingId = 0;
		mId = 0;
	}
	
}
