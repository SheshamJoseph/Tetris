#pragma once

#include <SDL2/SDL.h>
#include <iostream>

class Game
{
private:
    /* data */
    SDL_Window* m_window;   
    SDL_Surface* surface;
    SDL_Event e;
    bool quit {false};

public:
    Game();
    ~Game();
    bool tick();
};

