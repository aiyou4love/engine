#include "../../Engine.hpp"

namespace cc {
	
	const char * SelectStart::contextName()
	{
		return "selectStart";
	}
	
	void SelectStart::runContext()
	{
		SelectEngine& selectEngine_ = SelectEngine::instance();
		selectEngine_.runStart();
		
		mIsDelete = true;
	}
	
}
