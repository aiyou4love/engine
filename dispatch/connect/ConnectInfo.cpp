#include "../../Engine.hpp"

namespace cc {
	
	int32_t ConnectInfo::getDisconnectId()
	{
		return mDisconnectId;
	}
	
	int32_t ConnectInfo::getExceptionId()
	{
		return mExceptionId;
	}
	
	int32_t ConnectInfo::getConnectId()
	{
		return mConnectId;
	}
	
	int32_t ConnectInfo::getTimeoutId()
	{
		return mTimeoutId;
	}
	
	bool ConnectInfo::isDefault()
	{
		return ((0 == mConnectId) || (0 == mTimeoutId) || (0 == mDisconnectId)
			|| (0 == mExceptionId) || (0 == mConnectInfoId) );
	}
	
	int32_t ConnectInfo::getKey()
	{
		return mConnectInfoId;
	}
	
	ConnectInfo::ConnectInfo()
		: mConnectId (0)
		, mTimeoutId (0)
		, mDisconnectId (0)
		, mExceptionId (0)
		, mConnectInfoId (0)
	{
		
	}
	
	ConnectInfo::~ConnectInfo()
	{
		mConnectInfoId = 0;
		
		mConnectId = 0;
		mTimeoutId = 0;
		mDisconnectId = 0;
		mExceptionId = 0;
	}
	
}
