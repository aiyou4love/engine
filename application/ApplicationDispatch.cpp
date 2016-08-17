#include "../Engine.hpp"

namespace cc {
	
	void ApplicationDispatch::pushValue(ValuePtr& nValue)
	{
		EntityPtr& entity_ = ApplicationEngine::getEntity();
		entity_->pushValue(nValue);
	}
	
}
