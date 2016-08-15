#pragma once

namespace cc {
	
	class ISend : public Property
	{
	public:
		virtual void sendValue(ValuePtr& nValue) = 0;
	};
	typedef std::shared_ptr<ISend> SendPtr;
	
}
