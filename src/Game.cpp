#include "../include/Game.hpp"

Game::Game()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 360, 720, 0);
        if (m_window == nullptr)
        {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        }
        else
        {
            surface = SDL_GetWindowSurface(m_window);
        }
    }
}

Game::~Game()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool Game::tick()
{
    if (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
    }
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
    SDL_UpdateWindowSurface(m_window);

    return !quit;  // Return whether the game should keep running
}
