#pragma once

namespace cc {
	
	class LuaThread : public boost::enable_shared_from_this<LuaThread>, noncopyable
	{
	public:
		template<typename R, typename... A>
		R runCall(const char * nName, A... nArgs)
		{
			return lua_tinker::call<R>(mLuaState, nName, nArgs...);
		}
		
		void openFile(const char * nPath);
		void runStop();
		
		explicit LuaThread(lua_State * nLuaState, int nLuaRef);
		~LuaThread();
		
	private:
		lua_State * mLuaState;
		int mLuaRef;
	};
	typedef boost::shared_ptr<LuaThread> LuaThreadPtr;
	typedef boost::weak_ptr<LuaThread> LuaThreadWtr;
	
}
