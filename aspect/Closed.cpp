#include "../../Include.hpp"

namespace cc {
		
	int32_t Closed::getKey()
	{
		return mId;
	}
	
	Closed::Closed()
	{
		mConditions.clear();
		mDoings.clear();
		mId = 0;
	}
	
	Closed::~Closed()
	{
		mConditions.clear();
		mDoings.clear();
		mId = 0;
	}
	
}
