# ============================================================
# RTLog++ - Examples
# ============================================================
add_executable(sdl3_demo sdl3_demo.cpp)

target_link_libraries(sdl3_demo
        PRIVATE
        SDL3::SDL3
        utils
)

# ------------------------------------------------------------
# generico_demo — solo RTLog++, sin dependencias externas
# TODO: agregar generico_demo.cpp
# ------------------------------------------------------------
# add_executable(generico_demo generico_demo.cpp)
# target_link_libraries(generico_demo
#         PRIVATE
#         utils
# )