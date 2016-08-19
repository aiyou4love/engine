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

set( ASPECTS aspect/condition/Condition.cpp aspect/condition/Condition.hpp 
	aspect/condition/ConditionEngine.cpp aspect/condition/ConditionEngine.hpp 
	aspect/doing/Doing.cpp aspect/doing/Doing.hpp 
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

set( DISPATCH dispatch/accept/AcceptEngine.cpp dispatch/accept/AcceptEngine.hpp 
	dispatch/accept/AcceptIp.cpp dispatch/accept/AcceptIp.hpp 
	dispatch/accept/SessionMgr.cpp dispatch/accept/SessionMgr.hpp 
	dispatch/connect/ConnectEngine.cpp dispatch/connect/ConnectEngine.hpp 
	dispatch/connect/ConnectInfo.cpp dispatch/connect/ConnectInfo.hpp 
	dispatch/connect/ConnectIp.cpp dispatch/connect/ConnectIp.hpp 
	dispatch/connect/Connector.cpp dispatch/connect/Connector.hpp 
	dispatch/connect/ConnectSession.cpp dispatch/connect/ConnectSession.hpp 
	dispatch/send/ISend.hpp dispatch/dispatch/IDispatch.hpp 
	dispatch/ioservice/IoService.cpp dispatch/ioservice/IoService.hpp 
	dispatch/session/Session.cpp dispatch/session/Session.hpp )
	
set( CONSOLES console/ConsoleItem.cpp console/ConsoleItem.hpp 
	console/ConsoleUi.cpp console/ConsoleUi.hpp 
	console/CommandArgs.cpp console/CommandArgs.hpp 
	console/CommandBat.cpp console/CommandBat.hpp 
	console/ConsoleInput.cpp console/ConsoleInput.hpp 
	console/ConsoleUpdate.cpp console/ConsoleUpdate.hpp 
	console/ConsoleEngine.cpp console/ConsoleEngine.hpp )
	
if(${__GAMEEXE__} MATCHES "client")
add_library( libclient STATIC ${ASPECTS} ${ENGINES} ${DISPATCH} ${CONSOLES} )
install (TARGETS libclient DESTINATION $ENV{UNSEEN_ROOT}/lib)
endif()

if(${__GAMEEXE__} MATCHES "agent")
add_library( libagent STATIC ${ASPECTS} ${ENGINES} ${DISPATCH} ${CONSOLES} )
install (TARGETS libagent DESTINATION $ENV{UNSEEN_ROOT}/lib)
endif()


