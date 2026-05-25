# ============================================================
# RTLog++ - Root Build Script
# ============================================================
cmake_minimum_required(VERSION 3.22)
project(RTLog++
        VERSION 0.0.3 # Alpha
        LANGUAGES CXX
)
# ------------------------------------------------------------
# C++ Standard
# ------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# ------------------------------------------------------------
# Output ordenado
# ------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# ------------------------------------------------------------
# Create log/ directory at source root if it doesn't exist
# ------------------------------------------------------------
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/log")
# ------------------------------------------------------------
# SDL3 (download automatically) for examples
# ------------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.2.16
)
FetchContent_MakeAvailable(SDL3)
# ------------------------------------------------------------
# Project modules
# ------------------------------------------------------------
add_subdirectory(utils)
add_subdirectory(examples)