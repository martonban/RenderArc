cmake_minimum_required(VERSION 3.10)

project(GeoCore)

add_library(GeoCore INTERFACE)

target_include_directories(GeoCore INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(GeoCore INTERFACE glm::glm)

target_compile_features(GeoCore INTERFACE cxx_std_20)

add_subdirectory(examples)
