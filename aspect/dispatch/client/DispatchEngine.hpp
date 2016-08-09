#pragma once

#ifdef __CLIENT__
namespace cc {
	
	class DispatchEngine : noncopyable
	{
	public:
		void runIfSelect(IfSelectPtr& nIfSelect, EntityPtr& nEntity, ValuePtr& nValue);
		
		DispatchEngine();
		~DispatchEngine();
		
	private:
		static DispatchEngine mDispatchEngine;
	};
	
}
#endif
