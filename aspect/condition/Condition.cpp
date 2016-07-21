#include "../../Engine.hpp"

namespace cc {
	
	int8_t Condition::runCondition(EntityPtr& nEntity, ValuePtr& nValue)
	{
		LOGF;
		
		bool waite_ = false;
		bool reward_ = true;
		bool continue_ = false;
		auto it = mDoings.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			EdoingState doingState_ = nEntity->runCondition(doing_, nValue);
			if (EdoingState::mError == doingState_) {
				if (waite_) {
					nEntity->pushDoingState(doing_->getKey(), doingState_);
				}
				reward_ = false;
				break;
			} else if (EdoingState::mTrue == doingState_) {
				continue;
			} else if (EdoingState::mWaite == doingState_) {
				nEntity->pushDoingState(doing_->getKey(), doingState_);
				reward_ = false;
				waite_ = true;
				continue;
			} else if (EdoingState::mFalse == doingState_) {
				if (waite_) {
					nEntity->pushDoingState(doing_->getKey(), doingState_);
				}
				continue_ = true;
				reward_ = false;
				break;
			} else {
				reward_ = false;
				break;
			}
		}
		int8_t errorCode_ = 0;
		if (reward_) {
			errorCode_ += 1;
		}
		if (continue_) {
			errorCode_ += 2;
		}
		return errorCode_;
	}
	
	bool Condition::isDefault()
	{
		return ((0 == mConditionId) || (mDoings.size() <= 0));
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
