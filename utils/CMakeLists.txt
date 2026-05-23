add_library(utils STATIC
        rtLog.cpp
        rtLog.hpp
        ../examples/sdl3_demo.cpp
)

target_include_directories(utils
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(utils PUBLIC
        RTLOG_LOG_PATH="${CMAKE_SOURCE_DIR}/log/rtLog.log"
)