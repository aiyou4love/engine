#include "../Engine.hpp"

namespace cc {
	
	void ApplicationDispatch::pushValue(ValuePtr& nValue)
	{
		ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
		EntityPtr& entity_ = applicationEngine_.getEntity();
		entity_->pushValue(nValue);
	}
	
}
