cmake_minimum_required(VERSION 3.10)
project(RenderArc)

include(FetchContent)

# arca dependency
set(ARCA_VERSION v0.0.2-alpha)
FetchContent_Declare(
	Arca
	URL https://github.com/martonban/Arca/archive/refs/tags/${ARCA_VERSION}.tar.gz
)
FetchContent_MakeAvailable(Arca)

# json dependency
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

# raylib dependency
set(RAYLIB_VERSION 5.5)
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

# flecs dependency
include(FetchContent)
FetchContent_Declare(
  flecs
  GIT_REPOSITORY https://github.com/SanderMertens/flecs.git
  GIT_TAG master
)

FetchContent_MakeAvailable(flecs)