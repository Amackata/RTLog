# ============================================================
# RTLog++ - Root Build Script
# Version 0.0.1a
# ============================================================
cmake_minimum_required(VERSION 3.22)
project(RTLog++
        VERSION 0.0.1 # Alpha
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
#add_subdirectory(third_party)
#add_subdirectory(platform)