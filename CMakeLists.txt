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

set( RANDOMS random/RandomEngine.cpp random/RandomEngine.hpp )

set( ASPECTS aspect/condition/Condition.cpp aspect/condition/Condition.hpp 
	aspect/condition/ConditionEngine.cpp aspect/condition/ConditionEngine.hpp 
	aspect/doing/Doing.cpp aspect/doing/Doing.hpp aspect/doing/EdoingState.hpp 
	aspect/entity/Entity.cpp aspect/entity/Entity.hpp 
	aspect/reward/Reward.cpp aspect/reward/Reward.hpp 
	aspect/reward/RewardEngine.cpp aspect/reward/RewardEngine.hpp 
	aspect/select/IfSelect.cpp aspect/select/IfSelect.hpp 
	aspect/select/SelectEngine.cpp aspect/select/SelectEngine.hpp 
	aspect/select/Selector.cpp aspect/select/Selector.hpp 
	aspect/select/SelectState.cpp aspect/select/SelectState.hpp
	aspect/aspect/IAspect.hpp )

set( ENGINES Engine.cpp Engine.hpp )

set( UIS ui/UiEngine.cpp ui/UiEngine.hpp )
	
set( CONSOLES console/ConsoleItem.cpp console/ConsoleItem.hpp 
	console/ConsoleUi.cpp console/ConsoleUi.hpp 
	console/ConsoleEngine.cpp console/ConsoleEngine.hpp )
	
set( ACCOUNTS account/account/Account.cpp account/account/Account.hpp 
	account/account/AccountEngine.cpp account/account/AccountEngine.hpp 
	account/account/RoleItem.cpp account/account/RoleItem.hpp 
	account/account/ServerItem.cpp account/account/ServerItem.hpp 
	account/account/ServerList.cpp account/account/ServerList.hpp )
	
set( ACCOUNTC  account/client/UrlValue.cpp account/client/UrlValue.hpp 
	account/client/cAccount.cpp account/client/cAccount.hpp 
	account/client/cAccountEngine.cpp account/client/cAccountEngine.hpp 
	account/client/AgentResult.cpp account/client/AgentResult.hpp 
	account/client/LoginResult.cpp account/client/LoginResult.hpp 
	account/client/RoleResult.cpp account/client/RoleResult.hpp 
	account/client/ServerInfo.cpp account/client/ServerInfo.hpp 
	account/client/cRoleList.cpp account/client/cRoleList.hpp )

add_library( libengine STATIC ${RANDOMS} ${ASPECTS} ${ACCOUNTS} ${ACCOUNTC}
	${ENGINES} ${UIS} ${CONSOLES} )
	
install (TARGETS libengine DESTINATION $ENV{UNSEEN_ROOT}/lib)

