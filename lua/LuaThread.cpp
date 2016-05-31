#include "../Engine.hpp"

namespace cc {
	
	void LuaThread::openFile(const char * nPath)
	{
		lua_tinker::dofile(mLuaState, nPath);
	}
	
	void LuaThread::runStop()
	{
		lua_unref(mLuaState, mLuaRef);
	}
	
	LuaThread::LuaThread(lua_State * nLuaState, int nLuaRef)
		: mLuaState(nLuaState)
		, mLuaRef(nLuaRef)
	{
	}
	
	LuaThread::~LuaThread()
	{
	}
	
}
