#include "../../Engine.hpp"

namespace cc {
	
	void IfSelect::runIfSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mSelectors.begin();
		for ( ; it != mSelectors.end(); ++it ) {
			SelectorPtr& selector_ = it->second;
			if (selector_->runSelect(nEntity, nValue)) {
				break;
			}
		}
	}
	
	bool IfSelect::isDefault()
	{
		return ( (0 == mIfSelectId) || (mSelectors.size() <= 0) );
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
