cmake_minimum_required(VERSION 3.10)
project(RenderArc)

include(FetchContent)

# Arca Dependencies
FetchContent_Declare(
	Arca
	URL https://github.com/martonban/Arca/archive/refs/tags/v0.0.2-alpha.tar.gz
)
FetchContent_MakeAvailable(Arca)

# json dependency
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

# GLEW dependency
set(BUILD_UTILS OFF CACHE INTERNAL "")
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
FetchContent_Declare(
	GLEW
	URL https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.zip
	SOURCE_SUBDIR build/cmake
)
FetchContent_MakeAvailable(GLEW)
unset(CMAKE_POLICY_VERSION_MINIMUM)
target_include_directories(glew_s PUBLIC $<BUILD_INTERFACE:${glew_SOURCE_DIR}/include>)



# glm dependency
FetchContent_Declare(
	glm
	URL https://github.com/g-truc/glm/archive/refs/tags/1.0.3.tar.gz
)
FetchContent_MakeAvailable(glm)

# glfw dependency
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_Declare(
	glfw
	URL https://github.com/glfw/glfw/releases/download/3.4/glfw-3.4.zip
)
FetchContent_MakeAvailable(glfw)

# vulkan dependency
# find_package(Vulkan REQUIRED)


# application
add_subdirectory(application/SandBox)

# core libaries
add_subdirectory(core/graphics/GLCore)
add_subdirectory(core/graphics/GeoCore)
add_subdirectory(core/marathon)
