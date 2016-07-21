#include "../../Engine.hpp"

namespace cc {
	
	void IfSelect::runIfSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		LOGF;
		
		nEntity->startIfSelect(mIfSelectId);
		auto it = mSelectors.begin();
		for ( ; it != mSelectors.end(); ++it ) {
			SelectorPtr& selector_ = it->second;
			if (!selector_->runSelect(nEntity, nValue)) {
				break;
			}
		}
	}
	
	int32_t IfSelect::getKey()
	{
		return mIfSelectId;
	}
	
	IfSelect::IfSelect()
	{
		mSelectors.clear();
		mIfSelectId = 0;
	}
	
	IfSelect::~IfSelect()
	{
		mSelectors.clear();
		mIfSelectId = 0;
	}
	
}
