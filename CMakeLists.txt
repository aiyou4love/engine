cmake_minimum_required(VERSION 3.0)
project(engine)

if(WIN32)
	add_definitions( "-D_WIN32_WINNT=0x0601" )
	add_definitions( -D_CRT_SECURE_NO_WARNINGS )
	add_definitions( -D_SCL_SECURE_NO_WARNINGS )
	add_definitions( -DCURL_STATICLIB )
else()
	set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

include_directories($ENV{MARIADB_ROOT}/include)
include_directories($ENV{UNSEEN_ROOT}/include)
link_directories($ENV{UNSEEN_ROOT}/lib)

SET( LIBRARY_OUTPUT_PATH $ENV{UNSEEN_ROOT}/lib )

set(Boost_USE_STATIC_LIBS TRUE)
find_package(Boost COMPONENTS system exception date_time regex chrono thread filesystem log log_setup REQUIRED)

set( LUAS lua/lua_tinker.cpp lua/lua_tinker.hpp
	lua/LuaEngine.cpp lua/LuaEngine.hpp 
	lua/LuaThread.cpp lua/LuaThread.hpp )
	
set( RANDOMS random/RandomEngine.cpp random/RandomEngine.hpp )
	
add_library( ${PROJECT_NAME} STATIC ${LUAS} 
	${RANDOMS} )

