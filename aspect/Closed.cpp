#include "../../Include.hpp"

namespace cc {
	
	bool Closed::runCondition(EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine)
	{
		int32_t errorCode_ = 2;
		nEntity->startCondition(mId);
		map<int32_t, DoingPtr>::iterator it = mConditions.begin();
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
	
	void Closed::runDoing(EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine)
	{
		map<int32_t, DoingPtr>::iterator it = mDoings.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			nAspectEngine->runDoing(mId, doing_, nEntity, nValue);
		}
	}
	
	int32_t Closed::getKey()
	{
		return mId;
	}
	
	Closed::Closed()
	{
		mConditions.clear();
		mDoings.clear();
		mId = 0;
	}
	
	Closed::~Closed()
	{
		mConditions.clear();
		mDoings.clear();
		mId = 0;
	}
	
}
