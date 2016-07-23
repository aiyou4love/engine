#include "../../Engine.hpp"

namespace cc {
	
	void cNetEngine::initNet(EntityPtr& nEntity, const char * nIp, int32_t nPort, int32_t nRewardId)
	{
		LOGF;
	}
	
	void cNetEngine::sendNet(EntityPtr& nEntity, ValuePtr& nValue)
	{
		LOGF;
	}
	
	cNetEngine& cNetEngine::instance()
	{
		LOGF;
		
		return mNetEngine;
	}
	
	cNetEngine::cNetEngine()
	{
	}
	
	cNetEngine::~cNetEngine()
	{
	}
	
	cNetEngine cNetEngine::mNetEngine;
	
}
