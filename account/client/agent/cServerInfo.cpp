#include "../../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cServerInfo::setServerInfo(cServerInfo& nServerInfo)
	{
		mServerStart = nServerInfo.mServerStart;
	}
	
	int64_t cServerInfo::getServerStart()
	{
		return mServerStart;
	}
	
	cServerInfo::cServerInfo()
		: mServerStart (0)
	{
	}
	
	cServerInfo::cServerInfo(cServerInfo& nServerInfo)
		: mServerStart (nServerInfo.mServerStart)
	{
	}
	
	cServerInfo::~cServerInfo()
	{
		mServerStart = 0;
	}
#endif
	
}
