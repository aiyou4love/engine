#include "../../Include.hpp"

namespace cc {
	
	int8_t Condition::runCondition(EntityPtr& nEntity, ValuePtr& nValue)
	{
		int8_t errorCode_ = 2;
		auto it = mDoings.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			if ( nEntity->runCondition(doing_, nValue) ) {
				
			}
			if (EdoingState::mError == doingState_) {
				if (errorCode_ > 2) {
					nEntity->pushDoingState(doing_->getKey(), doingState_);
				}
				errorCode_ = 0;
				break;
			} else if (EdoingState::mTrue == doingState_) {
				continue;
			} else if (EdoingState::mWaite == doingState_) {
				nEntity->pushDoingState(doing_->getKey(), doingState_);
					errorCode_++;
					continue;
			} else if (EdoingState::mFalse == doingState_) {
				if (errorCode_ > 2) {
					nEntity->pushDoingState(doing_->getKey(), doingState_);
				}
				errorCode_ = 1;
				break;
			}
		}
		return (2 == errorCode_);
	}
	
	int32_t Condition::getKey()
	{
		return mConditionId;
	}
	
	Condition::Condition()
		: mConditionId (0)
	{
		mDoings.clear();
	}
	
	Condition::~Condition()
	{
		mConditionId = 0;
		
		mDoings.clear();
	}
	
}
