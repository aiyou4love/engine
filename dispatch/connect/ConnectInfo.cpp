#include "../../Engine.hpp"

namespace cc {
	
	int32_t ConnectInfo::getConnectErrorId()
	{
		return mConnectErrorId;
	}
	
	int32_t ConnectInfo::getConnectId()
	{
		return mConnectId;
	}
	
	int32_t ConnectInfo::getTimeoutId()
	{
		return mTimeoutId;
	}
	
	int32_t ConnectInfo::getDisconnectId()
	{
		return mDisconnectId;
	}
	
	int32_t ConnectInfo::getExceptionId()
	{
		return mExceptionId;
	}
	
	int16_t ConnectInfo::getDispatchId()
	{
		return mDispatchId;
	}
	
	bool ConnectInfo::isDefault()
	{
		return ((0 == mConnectId) || (0 == mTimeoutId) || (0 == mConnectErrorId) || (0 == mDisconnectId)
			|| (0 == mExceptionId) || (0 == mConnectInfoId) || (0 == mDispatchId) );
	}
	
	int32_t ConnectInfo::getKey()
	{
		return mConnectInfoId;
	}
	
	ConnectInfo::ConnectInfo()
		: mConnectInfoId (0)
		, mConnectErrorId (0)
		, mConnectId (0)
		, mTimeoutId (0)
		, mDisconnectId (0)
		, mExceptionId (0)
		, mDispatchId (0)
	{
		
	}
	
	ConnectInfo::~ConnectInfo()
	{
		mConnectInfoId = 0;
		
		mConnectErrorId = 0;
		mConnectId = 0;
		mTimeoutId = 0;
		
		mDisconnectId = 0;
		mExceptionId = 0;
		mDispatchId = 0;
	}
	
}
