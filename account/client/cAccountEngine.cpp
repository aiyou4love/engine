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
	
	void cAccountEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&cAccountEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&cAccountEngine::runLoad, this));
	}
	
	void cAccountEngine::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<cAccountEngine>("cAccountEngine");
		luaEngine_.runStatic<cAccountEngine>(&cAccountEngine::instance, "instance");
		luaEngine_.runMethod<cAccountEngine>(&cAccountEngine::runIfSelect, "runIfSelect");
	}
	
	void cAccountEngine::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<cAccountEngine *>(this, saveUrl(), saveName());
		
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runTable<cAccountEngine *>(this, streamUrl(), streamName());
	}
	
	const char * cAccountEngine::streamName()
	{
		return "cAccountEngine";
	}
	
	const char * cAccountEngine::streamUrl()
	{
		return "arc://cAccountEngine.json";
	}
	
	const char * cAccountEngine::streamName()
	{
		return "cAccountEngine";
	}
	
	const char * cAccountEngine::streamUrl()
	{
		return "arc://cAccountEngine.json";
	}
	
	cAccountEngine& cAccountEngine::instance()
	{
		return mAccountEngine;
	}
	
	cAccountEngine::cAccountEngine()
	{
	}
	
	cAccountEngine::~cAccountEngine()
	{
	}
	
	cAccountEngine cAccountEngine::mAccountEngine;
	
}
