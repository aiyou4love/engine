#include "../../Engine.hpp"

namespace cc {
	
	void SelectEngine::runIfSelect(int32_t nIfSelectId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mIfSelects.find(nIfSelectId);
		if ( it == mIfSelects.end() ) {
			LOGERROR("[%s]%d", __METHOD__, nIfSelectId);
			return;
		}
		IfSelectPtr& ifSelect_ = it->second;
		ifSelect_->runIfSelect(nEntity, nValue);
	}
	
	void SelectEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&SelectEngine::runLoad, this));
	}
	
	void SelectEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runTable<SelectEngine *>(this, streamUrl(), streamName());
	}
	
	const char * SelectEngine::streamName()
	{
		return "selectEngine";
	}
	
	const char * SelectEngine::streamUrl()
	{
		return "arc://selectEngine.json";
	}
	
	SelectEngine& SelectEngine::instance()
	{
		return mSelectEngine;
	}
	
	SelectEngine::SelectEngine()
	{
		mIfSelects.clear();
	}
	
	SelectEngine::~SelectEngine()
	{
		mIfSelects.clear();
	}
	
	SelectEngine SelectEngine::mSelectEngine;
	
}