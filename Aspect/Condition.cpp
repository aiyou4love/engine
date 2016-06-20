#include "../../Include.hpp"

namespace cc {
	
	bool Condition::runCondition(EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine)
	{
		int32_t errorCode_ = 2;
		nEntity->startCondition(mId);
		map<int32_t, DoingPtr>::iterator it = mDoings.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			EdoingState doingState_ = nAspectEngine->runCondition(mId, doing_, nEntity, nValue);
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
		return mId;
	}
	
	Condition::Condition()
		: mDoingId (0)
		, mId (0)
	{
		mDoings.clear();
	}
	
	Condition::~Condition()
	{
		mDoings.clear();
		mDoingId = 0;
		mId = 0;
	}
	
}
