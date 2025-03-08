#include <SDL2/SDL.h>
#include <iostream>

int main()
{
    // first create the window
    SDL_Window* m_window;   
    SDL_Surface* surface;

    // initialize sdl
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Error in initializing SDL2: " << SDL_GetError() << std::endl;
    }

    m_window = SDL_CreateWindow(
        "Sample window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 400,
        0
    );

    if (!m_window)
    {
        std::cerr << "Error opening window..." << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a surface
    surface = SDL_GetWindowSurface(m_window);
    if (!surface)
    {
        std::cerr << "Error opening window..." << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        return 1;
    }

    // fill the surface with color
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0,0,0));    // color: Black
    // update the surface
    SDL_UpdateWindowSurface(m_window);
    // keep screen open
    SDL_Event e;
    bool quit {false};
    while(!quit)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
                quit = true;
        }
    }


    SDL_DestroyWindow(m_window);

    return 0;
}
