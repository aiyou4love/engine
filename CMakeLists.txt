cmake_minimum_required(VERSION 3.0)
project(infrastructure)

if(WIN32)
	add_definitions("-D_WIN32_WINNT=0x0601")
	add_definitions( -D_CRT_SECURE_NO_WARNINGS )
	add_definitions( -D_SCL_SECURE_NO_WARNINGS )
else()
	set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

include_directories($ENV{MARIADB_ROOT}/include)
include_directories($ENV{UNSEEN_ROOT}/include)
link_directories($ENV{UNSEEN_ROOT}/lib)

set(Boost_USE_STATIC_LIBS TRUE)
find_package(Boost COMPONENTS system exception date_time regex chrono thread filesystem log log_setup REQUIRED)

set(MAINS Main.cpp)

set(LOGS log/LogEngine.hpp log/LogEngine.cpp)

add_executable(${PROJECT_NAME} ${MAINS} ${LOGS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

#add_library( ${PROJECT_NAME} STATIC ${LOGS} )
