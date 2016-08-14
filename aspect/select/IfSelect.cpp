#include "../../Engine.hpp"

namespace cc {
	
	void IfSelect::runIfSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mSelectors.begin();
		for ( ; it != mSelectors.end(); ++it ) {
			SelectorPtr& selector_ = it->second;
			if (!selector_->runSelect(nEntity, nValue)) {
				break;
			}
		}
	}
	
	int16_t IfSelect::getAppType()
	{
		return mAppType;
	}
	
	bool IfSelect::isDefault()
	{
		return ( (0 == mIfSelectId) || (mSelectors.size() <= 0) 
			 || (0 == mAppType) );
	}
	
	int32_t IfSelect::getKey()
	{
		return mIfSelectId;
	}
	
	IfSelect::IfSelect()
	{
		mAppType = EappType::mGameClient;
		
		mSelectors.clear();
		mIfSelectId = 0;
	}
	
	IfSelect::~IfSelect()
	{
		mAppType = EappType::mGameClient;
		
		mSelectors.clear();
		mIfSelectId = 0;
	}
	
}
