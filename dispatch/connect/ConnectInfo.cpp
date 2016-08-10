#include "../../Engine.hpp"

namespace cc {
	
	void ConnectInfo::setDisconnectId(int32_t nDisconnectId)
	{
		mDisconnectId = nDisconnectId;
	}
	
	void ConnectInfo::setExceptionId(int32_t nExceptionId)
	{
		mExceptionId = nExceptionId;
	}
	
	void ConnectInfo::setConnectId(int32_t nConnectId)
	{
		mConnectId = nConnectId;
	}
	
	void ConnectInfo::setTimeoutId(int32_t nTimeoutId)
	{
		mTimeoutId = nTimeoutId;
	}
	
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
	
	ConnectInfo::ConnectInfo()
		: mConnectId (0)
		, mTimeoutId (0)
		, mDisconnectId (0)
		, mExceptionId (0)
	{
		
	}
	
	ConnectInfo::~ConnectInfo()
	{
		mConnectId = 0;
		mTimeoutId = 0;
		mDisconnectId = 0;
		mExceptionId = 0;
	}
	
}
