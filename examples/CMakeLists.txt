# ============================================================
# RTLog++ - Examples
# Version 0.0.1a
# ============================================================

# SDL3 examples — requiere SDL3
find_package(SDL3 REQUIRED)

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