# ============================================================
# RTLog++ - Examples
# ============================================================
add_executable(sdl3_demo sdl3_demo.cpp)

target_link_libraries(sdl3_demo
        PRIVATE
        SDL3::SDL3
        utils
)

target_compile_definitions(sdl3_demo PRIVATE
        ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/")