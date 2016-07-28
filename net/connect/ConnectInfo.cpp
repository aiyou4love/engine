#include "../../Engine.hpp"

namespace cc {
	
	void ConnectInfo::setServerIp(const char * nServerIp)
	{
		mServerIp = nServerIp;
	}
	
	void ConnectInfo::setServerPort(const char * nServerPort)
	{
		mServerPort = nServerPort;
	}
	
	void ConnectInfo::setConnectId(int32_t nConnectId)
	{
		mConnectId = nConnectId;
	}
	
	void ConnectInfo::setTimeoutId(int32_t nTimeoutId)
	{
		mTimeoutId = nTimeoutId;
	}
	
	void ConnectInfo::setDisconnectId(int32_t nDisconnectId)
	{
		mDisconnectId = nDisconnectId;
	}
	
	void ConnectInfo::setAutoConnect(int8_t nAutoConnect)
	{
		mAutoConnect = ( (1 == nAutoConnect) ? true : false );
	}
	
	const char * ConnectInfo::getServerIp()
	{
		return mServerIp.c_str();
	}
	
	const char * ConnectInfo::getServerPort()
	{
		return mServerPort.c_str();
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
	
	bool ConnectInfo::getAutoConnect()
	{
		return mAutoConnect;
	}
	
	ConnectInfo::ConnectInfo()
		: mServerIp ("")
		, mServerPort ("")
		, mConnectId (0)
		, mTimeoutId (0)
		, mDisconnectId (0)
		, mAutoConnect (false)
	{
		
	}
	
	ConnectInfo::~ConnectInfo()
	{
		mServerIp = "";
		mServerPort = "";
		mConnectId = 0;
		mTimeoutId = 0;
		mDisconnectId = 0;
		mAutoConnect = false;
	}
	
}
