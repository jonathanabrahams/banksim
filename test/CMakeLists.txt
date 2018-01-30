cmake_minimum_required (VERSION 2.6)

### GOOGLE TEST SUBMODULE START
set(GOOGLETEST_ROOT ../externals/googletest/googletest CACHE STRING "Google Test source root")

include_directories(SYSTEM
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(gtest ${GOOGLETEST_SOURCES})
### GOOGLE TEST SUBMODULE END

### GOOGLE MOCK SUBMODULE START
set(GOOGLEMOCK_ROOT ../externals/googletest/googlemock CACHE STRING "Google Mock source root")

include_directories(SYSTEM
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}/include
    )

set(GOOGLEMOCK_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}/src/gmock-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}/src/gmock_main.cc
    )

foreach(_source ${GOOGLEMOCK_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(gmock ${GOOGLEMOCK_SOURCES})
### GOOGLE GMOCK SUBMODULE END

add_executable(runTests tests.cpp)

target_link_libraries(runTests gtest gmock pthread)
