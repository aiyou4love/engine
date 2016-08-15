#include "../../Engine.hpp"

namespace cc {
	
	const char * AcceptIp::getServerIp()
	{
		return mServerIp.c_str();
	}
	
	const char * AcceptIp::getServerPort()
	{
		return mServerPort.c_str();
	}
	
	bool AcceptIp::isDefault()
	{
		return ( ("" == mServerIp) || ("" == mServerPort) || (0 == mAcceptIpId) );
	}
	
	int16_t AcceptIp::getKey()
	{
		return mAcceptIpId;
	}
	
	AcceptIp::AcceptIp()
		: mServerIp ("")
		, mServerPort ("")
		, mAcceptIpId (0)
	{
		
	}
	
	AcceptIp::~AcceptIp()
	{
		mAcceptIpId = 0;
		mServerIp = "";
		mServerPort = "";
	}
	
}
