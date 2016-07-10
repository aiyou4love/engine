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
	aspect/select/SelectState.cpp aspect/select/SelectState.hpp )

add_library( libengine STATIC ${RANDOMS} ${ASPECTS} )

install (TARGETS libengine DESTINATION $ENV{UNSEEN_ROOT}/lib)
