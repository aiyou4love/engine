#include "../../Engine.hpp"

namespace cc {
	
	const char * ConnectIp::getServerIp()
	{
		return mServerIp.c_str();
	}
	
	const char * ConnectIp::getServerPort()
	{
		return mServerPort.c_str();
	}
	
	bool ConnectIp::isDefault()
	{
		return ( ("" == mServerIp) || ("" == mServerPort) || (0 == mConnectIpId) );
	}
	
	int32_t ConnectIp::getKey()
	{
		return mConnectIpId;
	}
	
	ConnectIp::ConnectIp()
		: mServerIp ("")
		, mServerPort ("")
		, mConnectIpId (0)
	{
		
	}
	
	ConnectIp::~ConnectIp()
	{
		mConnectIpId = 0;
		mServerIp = "";
		mServerPort = "";
	}
	
}
