#include "../../Engine.hpp"

namespace cc {
	
	void SelectEngine::runIfSelect(int32_t nIfSelectId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mIfSelects.find(nIfSelectId);
		if ( it == mIfSelects.end() ) {
			LOGE("[%s]%d", __METHOD__, nIfSelectId);
			return;
		}
		IfSelectPtr& ifSelect_ = it->second;
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		
		int16_t appType_ = ifSelect_->getAppType();
		int16_t appType1_ = workDirectory_.getAppType();
		
		if ( (appType_ & appType1_) > 0 ) {
			ifSelect_->runIfSelect(nEntity, nValue);
		} else {
			DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
			dispatchEngine_->runIfSelect(ifSelect_, nEntity, nValue);
		}
	}
	
	void SelectEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&SelectEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&SelectEngine::runLoad, this));
	}
	
	void SelectEngine::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<SelectEngine>("SelectEngine");
		luaEngine_.runStatic<SelectEngine>(SelectEngine::instance, "instance");
		luaEngine_.runMethod<SelectEngine>(&SelectEngine::runIfSelect, "runIfSelect");
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
		return "selectEngine.json";
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
