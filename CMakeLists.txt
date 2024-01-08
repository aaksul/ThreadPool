cmake_minimum_required(VERSION 3.0.0)
project(thread_example VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/util)

add_library(option src/options.cc)
add_library(env_posix src/env_posix.cc)
add_library(thread_pool util/thread_pool.cc)
add_executable(thread_example thread_main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
