cmake_minimum_required(VERSION 3.10)

project(Marathon)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)


file(GLOB_RECURSE MARATHON_SOURCES "src/*.cpp")

add_library(Marathon SHARED
    ${MARATHON_SOURCES}
)

target_include_directories(Marathon PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(Marathon PRIVATE MARATHON_LIB_EXPORT Arca)