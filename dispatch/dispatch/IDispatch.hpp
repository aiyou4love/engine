#pragma once

namespace cc {
	
	class IDispatch : noncopyable
	{
	public:
		virtual void pushValue(ValuePtr& nValue) = 0;
	};
	typedef std::shared_ptr<IDispatch> DispatchPtr;
	
}
