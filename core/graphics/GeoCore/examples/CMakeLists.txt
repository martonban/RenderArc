cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE GEOCORE_EXAMPLE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(GeoCoreExamples ${GEOCORE_EXAMPLE_SOURCES})

target_link_libraries(GeoCoreExamples PRIVATE GeoCore)
