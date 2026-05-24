# ============================================================
# RTLog++ - Root Build Script
# ============================================================

cmake_minimum_required(VERSION 3.22)
project(RTLog++
        VERSION 0.0.2 # Alpha
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
# Project modules
# ------------------------------------------------------------
add_subdirectory(utils)
add_subdirectory(examples)

# ------------------------------------------------------------
# Root launcher
# ------------------------------------------------------------
add_executable(RTLog main.cpp)
target_link_libraries(RTLog PRIVATE utils)
target_compile_definitions(RTLog PRIVATE
        RTLOG_BIN_DIR="${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)
add_dependencies(RTLog sdl3_demo)