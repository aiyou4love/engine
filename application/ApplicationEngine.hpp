#pragma once

namespace cc {
	
	class ApplicationEngine : public AspectEngine
	{
	public:
		DispatchPtr& getDispatch();
		EntityPtr& getEntity();
		
		void runPreinit();
		void runClear();
		
		ApplicationEngine& instance();
		
		ApplicationEngine();
		~ApplicationEngine();
		
	private:
		static ApplicationEngine mApplicationEngine;
		
		DispatchPtr mDispatch;
		EntityPtr mEntity;
	};
	
}
