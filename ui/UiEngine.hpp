#pragma once

namespace cc {
	
	class UiEngine : noncopyable
	{
	public:
		void showUi(const char * nName);
		
		void refreshUi(const char * nName, IndexValue& nIndexValue);
		
		void closeUi();
		void clearUi();
		
		static UiEngine& instance();
		
		UiEngine();
		~UiEngine();
		
	private:
		static UiEngine mUiEngine;
	};
	
}
