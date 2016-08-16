#pragma once

namespace cc {
	
	class ApplicationEngine : public AspectEngine
	{
	public:
		EntityPtr& getEntity();
		
		void runPreinit();
		void runClear();
		
		ApplicationEngine& instance();
		
		ApplicationEngine();
		~ApplicationEngine();
		
	private:
		static ApplicationEngine mApplicationEngine;
		
		EntityPtr mEntity;
	};
	
}
