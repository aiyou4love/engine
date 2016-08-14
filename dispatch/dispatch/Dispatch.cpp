#pragma once

namespace cc {
	
	class Dispatch : public IDispatch
	{
	public:
		void runValue(IfSelectPtr& nIfSelect, EntityPtr& nEntity, ValuePtr& nValue) = 0;
		
		void pushValue(ValuePtr& nValue) = 0;
	};
	typedef std::shared_ptr<IDispatch> DispatchPtr;
	
}
