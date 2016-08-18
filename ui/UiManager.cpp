#include "../Engine.hpp"

namespace cc {
	
	void UiManager::showUi(const char * nName)
	{
		auto it = mUiEngines.begin();
		for ( ; it != mUiEngines.end(); ++it ) {
			IUiEngine * uiEngine_ = (*it);
			uiEngine_->showUi(nName);
		}
	}
	
	void UiManager::loadUi(const char * nName)
	{
		auto it = mUiEngines.begin();
		for ( ; it != mUiEngines.end(); ++it ) {
			IUiEngine * uiEngine_ = (*it);
			uiEngine_->loadUi(nName);
		}
	}
	
	void UiManager::refreshUi(const char * nName, IndexValue& nIndexValue)
	{
		auto it = mUiEngines.begin();
		for ( ; it != mUiEngines.end(); ++it ) {
			IUiEngine * uiEngine_ = (*it);
			uiEngine_->refreshUi(nName, nIndexValue);
		}
	}
	
	void UiManager::closeUi(const char * nName)
	{
		auto it = mUiEngines.begin();
		for ( ; it != mUiEngines.end(); ++it ) {
			IUiEngine * uiEngine_ = (*it);
			uiEngine_->closeUi(nName);
		}
	}
	
	void UiManager::clearUi()
	{
		auto it = mUiEngines.begin();
		for ( ; it != mUiEngines.end(); ++it ) {
			IUiEngine * uiEngine_ = (*it);
			uiEngine_->clearUi();
		}
	}
	
	UiManager& UiManager::instance()
	{
		return mUiManager;
	}
	
	UiManager::UiManager()
	{
		mUiEngines.clear();
	}
	
	UiManager::~UiManager()
	{
		mUiEngines.clear();
	}
	
	UiManager UiManager::mUiManager;
	
}
