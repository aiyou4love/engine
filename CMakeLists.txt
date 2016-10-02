cmake_minimum_required(VERSION 3.0)
project(engine)

if(WIN32)
	add_definitions( "-D_WIN32_WINNT=0x0601" )
	add_definitions( -D_CRT_SECURE_NO_WARNINGS )
	add_definitions( -D_SCL_SECURE_NO_WARNINGS )
	add_definitions( -DCURL_STATICLIB )
else()
	set(CMAKE_CXX_FLAGS "-std=c++14")
endif()

string(TOUPPER ${__GAMEEXE__} __PROJNAME__)
add_definitions(-D__${__PROJNAME__}__)

include_directories($ENV{MARIADB_ROOT}/include)
include_directories($ENV{UNSEEN_ROOT}/include)
link_directories($ENV{UNSEEN_ROOT}/lib)

set(Boost_USE_STATIC_LIBS TRUE)
find_package(Boost COMPONENTS system exception date_time regex chrono thread filesystem log log_setup REQUIRED)

set( TIMES time/time/TimeEngine.cpp time/time/TimeEngine.hpp 
	time/time/ServerTime.cpp time/time/ServerTime.hpp 
	time/client/cServerTime.cpp time/client/cServerTime.hpp 
	time/server/cServerTime.cpp time/server/cServerTime.hpp )
	
set( ACCOUNTS account/account/Account.cpp account/account/Account.hpp
	account/account/AccountEngine.cpp account/account/AccountEngine.hpp
	account/agent/cAccount.cpp account/agent/cAccount.hpp
	account/agent/cAccountEngine.cpp account/agent/cAccountEngine.hpp
	account/social/cAccount.cpp account/social/cAccount.hpp
	account/social/cAccountEngine.cpp account/social/cAccountEngine.hpp
	account/client/EaccountId.hpp
	account/client/cRoleResult.cpp account/client/cRoleResult.hpp
	account/client/cLoginResult.cpp account/client/cLoginResult.hpp
	account/client/cAccountEngine.cpp account/client/cAccountEngine.hpp )
	
set( ENGINES Engine.cpp Engine.hpp )
	
if(${__GAMEEXE__} MATCHES "client")
add_library( libclient STATIC ${TIMES} ${ENGINES} ${ACCOUNTS} )
install (TARGETS libclient DESTINATION $ENV{UNSEEN_ROOT}/lib)
endif()

if(${__GAMEEXE__} MATCHES "agent")
add_library( libagent STATIC ${TIMES} ${ENGINES} ${ACCOUNTS} )
install (TARGETS libagent DESTINATION $ENV{UNSEEN_ROOT}/lib)
endif()


