cmake_minimum_required(VERSION 3.10)

project(GLCore)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)


file(GLOB_RECURSE GL_CORE_SOURCES "src/*.cpp")

add_library(GLCore SHARED
    ${GL_CORE_SOURCES}
    include/buffers/IndexBuffer.hpp
)

target_include_directories(GLCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/instance
    ${CMAKE_CURRENT_SOURCE_DIR}/include/utils
        ${CMAKE_CURRENT_SOURCE_DIR}/include/shader
)

target_link_libraries(GLCore PUBLIC glfw glew_s glm::glm)

target_compile_definitions(GLCore PRIVATE GL_CORE_LIB_EXPORT)