cmake_minimum_required (VERSION 2.6)
project (Simulator)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED OFF)
set(Boost_USE_STATIC_RUNTIME ON)

find_package(Boost 1.55.0 COMPONENTS system )

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(main main.cpp)
    target_link_libraries(main ${Boost_LIBRARIES})
endif()
