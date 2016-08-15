#include "../../Engine.hpp"

namespace cc {
	
	int32_t AcceptInfo::getDisconnectId()
	{
		return mDisconnectId;
	}
	
	int32_t AcceptInfo::getExceptionId()
	{
		return mExceptionId;
	}
	
	int16_t AcceptInfo::getDispatchId()
	{
		return mDispatchId;
	}
	
	bool AcceptInfo::isDefault()
	{
		return ( (0 == mDisconnectId) || (0 == mExceptionId)
			|| (0 == mAcceptInfoId) || (0 == mDispatchId) );
	}
	
	int16_t ConnectInfo::getKey()
	{
		return mAcceptInfoId;
	}
	
	ConnectInfo::ConnectInfo()
		: mAcceptInfoId (0)
		, mDisconnectId (0)
		, mExceptionId (0)
		, mDispatchId (0)
	{
	}
	
	ConnectInfo::~ConnectInfo()
	{
		mAcceptInfoId = 0;
		
		mDisconnectId = 0;
		mExceptionId = 0;
		mDispatchId = 0;
	}
	
}
