#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
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
		luaEngine_.runStatic<cAccountEngine>(cAccountEngine::instance, "instance");
	}
	
	void cAccountEngine::runLoad()
	{
	}
	
	const char * cAccountEngine::streamName()
	{
		return "accountEngine";
	}
	
	const char * cAccountEngine::streamUrl()
	{
		return "accountEngine.json";
	}
	
	const char * cAccountEngine::saveName()
	{
		return "cAccountEngine";
	}
	
	const char * cAccountEngine::saveUrl()
	{
		return "cAccountEngine.json";
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
#endif

}
