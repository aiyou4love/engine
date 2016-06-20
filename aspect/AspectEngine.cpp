#include "../../Include.hpp"

namespace cc {
	
	EdoingState AspectEngine::runCondition(int32_t nCloseId, DoingPtr& nDoing, EntityPtr& nEntity, ValuePtr& nValue)
	{
		int32_t aspectId_ = nDoing->getAspectId();
		int32_t doingId_ = nDoing->getDoingId();
		map<int32_t, IAspect *>::iterator it = mAspects.find(aspectId_);
		if ( it == mAspects.end() ) {
			LOGERROR("[%s]%d", __METHOD__, aspectId_);
			return false;
		}
		IAspect * aspect_ = mAspects[aspectId_];
		return aspect_->runCondition(nCloseId, doingId_, nEntity, nValue);
	}
	
	void AspectEngine::runDoing(int32_t nCloseId, DoingPtr& nDoing, EntityPtr& nEntity, ValuePtr& nValue)
	{
		int32_t aspectId_ = nDoing->getAspectId();
		int32_t doingId_ = nDoing->getDoingId();
		map<int32_t, IAspect *>::iterator it = mAspects.find(aspectId_);
		if ( it == mAspects.end() ) {
			LOGERROR("[%s]%d", __METHOD__, aspectId_);
			return false;
		}
		IAspect * aspect_ = mAspects[aspectId_];
		aspect_->runDoing(nCloseId, doingId_, nEntity, nValue);
	}
	
	void AspectEngine::runRegister(int32_t nId, IAspect * nAspect)
	{
		map<int32_t, IAspect *>::iterator it = mAspects.find(nId);
		if ( it != mAspects.end() ) {
			LOGERROR("[%s]%d", __METHOD__, nId);
			return;
		}
		mAspects[nId] = nAspect;
	}
	
	AspectEngine::AspectEngine()
	{
		mAspects.clear();
	}
	
	AspectEngine::~AspectEngine()
	{
		mAspects.clear();
	}
	
}
