#include "../../Engine.hpp"

namespace cc {
	
	void DispatchEngine::runIfSelect(IfSelectPtr& nIfSelect, EntityPtr& nEntity, ValuePtr& nValue)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		
		int16_t appType_ = ifSelect_->getAppType();
		int16_t appType1_ = workDirectory_.getAppType();
		if ( EappType::mGameClient == appType1_ ) {
			
		} else 
			
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
