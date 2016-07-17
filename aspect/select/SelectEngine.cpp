#include "../../Engine.hpp"

namespace cc {
	
	void SelectEngine::runIfSelect(int32_t nIfSelectId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		LOGF;
		
		auto it = mIfSelects.find(nIfSelectId);
		if ( it == mIfSelects.end() ) {
			LOGE("[%s]%d", __METHOD__, nIfSelectId);
			return;
		}
		IfSelectPtr& ifSelect_ = it->second;
		ifSelect_->runIfSelect(nEntity, nValue);
	}
	
	void SelectEngine::runPreinit()
	{
		LOGF;
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&SelectEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&SelectEngine::runLoad, this));
	}
	
	void SelectEngine::runLuaApi()
	{
		LOGF;
		
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<SelectEngine>("SelectEngine");
		luaEngine_.runStatic<SelectEngine>(SelectEngine::instance, "instance");
		luaEngine_.runMethod<SelectEngine>(&SelectEngine::runIfSelect, "runIfSelect");
	}
	
	void SelectEngine::runLoad()
	{
		LOGF;
		
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
		LOGF;
		
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
