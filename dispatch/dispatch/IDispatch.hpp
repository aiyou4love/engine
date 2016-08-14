#pragma once

namespace cc {
	
	class IDispatch : public Property
	{
	public:
		virtual void runValue(IfSelectPtr& nIfSelect, EntityPtr& nEntity, ValuePtr& nValue) = 0;
		
		virtual void pushValue(ValuePtr& nValue) = 0;
	};
	typedef std::shared_ptr<IDispatch> DispatchPtr;
	
}
