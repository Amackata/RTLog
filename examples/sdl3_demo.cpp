/*************************************************************
* RTLog++ - Example: Minimal SDL3 Window
* Demonstrates RTLog++ integration with SDL3
*************************************************************/
#include <SDL3/SDL.h>
#include "rtLog.hpp"

int main()
{
    RTLog& log = RTLog::get();
    log.runLogger();

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        log.errorLog(SDL_GetError());
        return 1;
    }
    log.infoLog("SDL3 initialized");

    SDL_Window* window = SDL_CreateWindow("RTLog++ SDL3 Window", 800, 600, 0);
    if (!window)
    {
        log.errorLog(SDL_GetError());
        SDL_Quit();
        return 1;
    }
    log.infoLog("Window created: 800x600");

    SDL_Event e;
    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
            {
                log.infoLog("Quit event received");
                running = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    log.infoLog("Shutdown complete");

    return 0;
}