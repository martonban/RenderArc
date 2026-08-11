cmake_minimum_required(VERSION 3.10)

project(GLCore)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)


file(GLOB_RECURSE GL_CORE_SOURCES "src/*.cpp")

add_library(GLCore SHARED
    ${GL_CORE_SOURCES}
)

function(add_all_includes target directory)
    target_include_directories(${target} PUBLIC ${directory})
    file(GLOB subdirs RELATIVE ${directory} "${directory}/*")
    foreach(subdir ${subdirs})
        if(IS_DIRECTORY "${directory}/${subdir}")
            add_all_includes(${target} "${directory}/${subdir}")
        endif()
    endforeach()
endfunction()

add_all_includes(GLCore ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(GLCore PUBLIC glfw glew_s glm::glm GeoCore)

target_compile_definitions(GLCore PRIVATE GL_CORE_LIB_EXPORT)