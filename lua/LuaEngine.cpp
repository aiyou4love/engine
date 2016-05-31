#include "../Engine.hpp"

namespace cc {
	
	LuaThreadPtr LuaEngine::createLuaThread()
	{
		lua_State * luaState_ = lua_newthread(mLuaState);
		lua_pushthread(luaState_);
		int luaRef_ = lua_ref(luaState_, LUA_REGISTRYINDEX);
		return LuaThreadPtr(new LuaThread(luaState_, luaRef_));
	}
	
	void LuaEngine::runClose()
	{
		lua_close(mLuaState);
	}
	
	LuaEngine& LuaEngine::instance()
	{
		return mLuaEngine;
	}

	LuaEngine::LuaEngine()
	{
		mLuaState = lua_open();
		luaL_openlibs(mLuaState);
	}
	
	LuaEngine::~LuaEngine()
	{
		this->runClose();
	}
	
}
