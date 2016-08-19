#pragma once

namespace cc {
	
	class UiManager : noncopyable
	{
	public:
		void showUi(const char * nName);
		void loadUi(const char * nName);
		
		void refreshUi(const char * nName, IndexValue& nIndexValue);
		
		void closeUi(const char * nName);
		void clearUi();
		
		void registerEngine(IUiEngine * nUiEngine);
		
		static UiManager& instance();
		
		UiManager();
		~UiManager();
		
	private:
		list<IUiEngine *> mUiEngines;
		
		static UiManager mUiManager;
	};
	
}
