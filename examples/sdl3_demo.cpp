/*************************************************************
* RTLog++ - Example: Minimal SDL3 Window
* Demonstrates RTLog++ log levels with real SDL3 scenarios
*************************************************************/
#include <SDL3/SDL.h>
#include "rtLog.hpp"

int main()
{
    RTLog& log = RTLog::get();
    log.info("RTLog++ started");


    // -------------------------
    // SDL3 Init
    // -------------------------
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        log.fatal(SDL_GetError());
        return 1;
    }
    log.info("SDL3 initialized");

    // -------------------------
    // Window
    // -------------------------
    SDL_Window* window = SDL_CreateWindow("RTLog++ SDL3 Window", 800, 600, 0);
    if (!window)
    {
        log.fatal("Window creation failed", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    log.info("Window created: 800x600");

    // -------------------------
    // Renderer
    // -------------------------
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer)
    {
        log.fatal("Renderer creation failed", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    log.info("Renderer created");

    // DEBUG: diagnostic info
    log.debug("Renderer backend", SDL_GetRendererName(renderer));

    // WARNING: adaptive vsync (-1) no soportado en todos los drivers
    if (!SDL_SetRenderVSync(renderer, -1))
        log.warning("Adaptive vsync not supported, fallback disabled", SDL_GetError());

    // ERROR: asset requerido no encontrado
    SDL_Surface* bg = SDL_LoadBMP("assets/background.bmp");
    if (!bg)
        log.error("Required asset not found", SDL_GetError());

    // FATAL: simulated critical condition - something got really, really wrong
    log.fatal("Simulated: critical GPU memory failure - shutdown forced");

    // -------------------------
    // Event loop
    // -------------------------
    SDL_Event e;
    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
            {
                log.info("Quit event received");
                running = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    // -------------------------
    // Cleanup
    // -------------------------
    if (bg) SDL_DestroySurface(bg); // spoiler: bg is always null in this demo
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    log.info("Shutdown complete");

    return 0;
}