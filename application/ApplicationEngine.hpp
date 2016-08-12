#pragma once

namespace cc {
	
	class ApplicationEngine : public AspectEngine
	{
	public:
		EntityPtr& getEntity();
		
		ApplicationEngine& instance();
		
		ApplicationEngine();
		~ApplicationEngine();
		
	private:
		static ApplicationEngine mApplicationEngine;
		
		EntityPtr mEntity;
	};
	
}
