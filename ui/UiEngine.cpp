#include "../Engine.hpp"

namespace cc {
	
	void UiEngine::showUi(const char * nName)
	{
		auto it = mUiEntitys.find(nName);
		if ( it != mUiEntitys.end() ) {
			LOGE("[%s]%s", __METHOD__, nName);
			return;
		}
		UiEntityPtr uiEntity_(new UiEntity(nName));
		mUiEntitys[nName] = uiEntity_;
		uiEntity_->runShow();
	}
	
	void UiEngine::refreshUi(const char * nName, const char * nEvent)
	{
		auto it = mUiEntitys.find(nName);
		if ( it == mUiEntitys.end() ) {
			LOGE("[%s]%s", __METHOD__, nName);
			return;
		}
		UiEntityPtr& uiEntity_ = it->second;
		uiEntity_->runRefresh(nEvent);
	}
	
	void UiEngine::closeUi(const char * nName)
	{
		auto it = mUiEntitys.find(nName);
		if ( it == mUiEntitys.end() ) {
			LOGE("[%s]%s", __METHOD__, nName);
			return;
		}
		UiEntityPtr& uiEntity_ = it->second;
		uiEntity_->runClose();
		mUiEntitys.erase(it);
	}
	
	void UiEngine::runPreinit()
	{
		
	}
	
	UiEngine& UiEngine::instance()
	{
		return mUiEngine;
	}
	
	UiEngine::UiEngine()
	{
		mUiEntitys.clear();
	}
	
	UiEngine::~UiEngine()
	{
		mUiEntitys.clear();
	}
	UiEngine UiEngine::mUiEngine;
	
}
