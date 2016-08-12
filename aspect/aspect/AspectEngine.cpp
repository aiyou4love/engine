#include "../Engine.hpp"

namespace cc {
	
	bool AspectEngine::runCondition(DoingPtr& nDoing, ValuePtr& nValue)
	{
		int32_t aspectId_= nDoing->getAspectId();
		int32_t doingId_= nDoing->getDoingId();
		auto it = mAspects.find(aspectId_);
		if ( it == mAspects.end() ) {
			LOGE("[%s]%d", __METHOD__, aspectId_);
			return false;
		}
		IAspect * aspect_ = it->second;
		return aspect_->runCondition(doingId_, mAccount, nValue);
	}
	
	void AspectEngine::runReward(DoingPtr& nDoing, ValuePtr& nValue)
	{
		int32_t aspectId_= nDoing->getAspectId();
		int32_t doingId_= nDoing->getDoingId();
		auto it = mAspects.find(aspectId_);
		if ( it == mAspects.end() ) {
			LOGE("[%s]%d", __METHOD__, aspectId_);
			return;
		}
		IAspect * aspect_ = it->second; 
		return aspect_->runReward(doingId_, mAccount, nValue);
	}
	
	void AspectEngine::registerAspect(int32_t nAspectId, IAspect * nAspect)
	{
		auto it = mAspects.find(nAspectId);
		if ( it != mAspects.end() ) {
			LOGE("[%s]%d", __METHOD__, nAspectId);
			return;
		}
		mAspects[nAspectId] = nAspect;
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
