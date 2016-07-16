#pragma once

namespace cc {
	
	class UiEngine : noncopyable
	{
	public:
		void showUi(const char * nName);
		void refreshUi(const char * nName, const char * nEvent);
		void closeUi(const char * Name);
		
		void runPreinit();
		
		static UiEngine& instance();
		
		UiEngine();
		~UiEngine();
		
	private:
		map<string, UiEntityPtr> mUiEntitys;
		
		static UiEngine mUiEngine;
	};
	
}
