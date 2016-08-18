#pragma once

namespace cc {
	
	class IUiEngine : noncopyable
	{
	public:
		virtual void showUi(const char * nName) = 0;
		virtual void loadUi(const char * nName) = 0;
		
		virtual void refreshUi(const char * nName, IndexValue& nIndexValue) = 0;
		
		virtual void closeUi(const char * nName) = 0;
		virtual void clearUi() = 0;
	};
	
}
