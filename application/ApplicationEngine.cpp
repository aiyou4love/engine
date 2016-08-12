#include "../Engine.hpp"

namespace cc {
	
	EntityPtr& ApplicationEngine::getEntity()
	{
		return mEntity;
	}
	
	ApplicationEngine& ApplicationEngine::instance()
	{
		return mApplicationEngine;
	}
	
	ApplicationEngine::ApplicationEngine()
		: mEntity (new Application())
	{
	}
	
	ApplicationEngine::~ApplicationEngine()
	{
	}
	
	ApplicationEngine ApplicationEngine::mApplicationEngine;
	
}
