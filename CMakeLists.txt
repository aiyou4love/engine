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

add_definitions(-D__RUNING__)

include_directories($ENV{MARIADB_ROOT}/include)
include_directories($ENV{UNSEEN_ROOT}/include)
link_directories($ENV{UNSEEN_ROOT}/lib)

set(Boost_USE_STATIC_LIBS TRUE)
find_package(Boost COMPONENTS system exception date_time regex chrono thread filesystem log log_setup REQUIRED)

set( ASPECTS aspect/condition/Condition.cpp aspect/condition/Condition.hpp 
	aspect/condition/ConditionEngine.cpp aspect/condition/ConditionEngine.hpp 
	aspect/doing/Doing.cpp aspect/doing/Doing.hpp aspect/doing/EdoingState.hpp 
	aspect/entity/Property.cpp aspect/entity/Property.hpp 
	aspect/entity/Entity.cpp aspect/entity/Entity.hpp 
	aspect/reward/Reward.cpp aspect/reward/Reward.hpp 
	aspect/reward/RewardEngine.cpp aspect/reward/RewardEngine.hpp 
	aspect/select/IfSelect.cpp aspect/select/IfSelect.hpp 
	aspect/select/SelectEngine.cpp aspect/select/SelectEngine.hpp 
	aspect/select/Selector.cpp aspect/select/Selector.hpp 
	aspect/select/SelectStart.cpp aspect/select/SelectStart.hpp
	aspect/aspect/AspectEngine.cpp aspect/aspect/AspectEngine.hpp 
	aspect/aspect/IAspect.hpp )

set( ENGINES Engine.cpp Engine.hpp )

set( NETS net/net/NetEngine.cpp net/net/NetEngine.hpp 
	net/ioservice/IoService.cpp net/ioservice/IoService.hpp 
	net/session/Session.cpp net/session/Session.hpp 
	net/connect/ConnectInfo.cpp net/connect/ConnectInfo.hpp 
	net/connect/TcpConnector.cpp net/connect/TcpConnector.hpp )
	
if(${__GAMEEXE__} MATCHES "client")
add_library( libclient STATIC ${ASPECTS} ${ACCOUNTS} ${ACCOUNTC}
	${ENGINES} ${UIS} ${CONSOLES} ${NETS} )
install (TARGETS libclient DESTINATION $ENV{UNSEEN_ROOT}/lib)
endif()

if(${__GAMEEXE__} MATCHES "agent")
add_library( libagent STATIC ${ASPECTS} ${ACCOUNTS} ${ACCOUNTC}
	${ENGINES} ${UIS} ${CONSOLES} ${NETS} )
install (TARGETS libagent DESTINATION $ENV{UNSEEN_ROOT}/lib)
endif()


