add_library(utils STATIC
        rtLogger.cpp
        rtLogger.hpp
)


target_include_directories(utils
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)