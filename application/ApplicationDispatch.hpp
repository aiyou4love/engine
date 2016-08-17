#pragma once

namespace cc {
	
	class ApplicationDispatch : public IDispatch
	{
	public:
		void pushValue(ValuePtr& nValue);
	};
	
}
