#include "../../../Engine.hpp"

#ifdef __CLIENT__
namespace cc {
	
	void DispatchEngine::runIfSelect(IfSelectPtr& nIfSelect, EntityPtr& nEntity, ValuePtr& nValue)
	{
		
	}
	
	DispatchEngine& DispatchEngine::instance()
	{
		return mDispatchEngine;
	}
	
	DispatchEngine::DispatchEngine()
	{
	}
	
	DispatchEngine::~DispatchEngine()
	{
	}
	
	DispatchEngine DispatchEngine::mDispatchEngine;
	
}
#endif

