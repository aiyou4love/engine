#include "../../Engine.hpp"

namespace cc {
	
	void ConnectIp::setServerPort(const char * nServerPort)
	{
		mServerPort = nServerPort;
	}
	
	void ConnectIp::setServerIp(const char * nServerIp)
	{
		mServerIp = nServerIp;
	}
	
	const char * ConnectIp::getServerIp()
	{
		return mServerIp.c_str();
	}
	
	const char * ConnectIp::getServerPort()
	{
		return mServerPort.c_str();
	}
	
	ConnectIp::ConnectIp()
		: mServerIp ("")
		, mServerPort ("")
	{
		
	}
	
	ConnectIp::~ConnectIp()
	{
		mServerIp = "";
		mServerPort = "";
	}
	
}
