#pragma once

namespace cc {
	
	class ISend : public Property
	{
	public:
		virtual void sendValue(ValuePtr& nValue) = 0;
	};
	typedef SPTR<ISend> SendPtr;
	
}
