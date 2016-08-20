#pragma once

namespace cc {
	
	class SelectStart : public Context
	{
	public:
		const char * contextName();
		
		void runContext();
	};
	typedef SPTR<SelectStart> SelectStartPtr;
	
}
