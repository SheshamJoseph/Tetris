#include "../include/IO.hpp"

IO::IO()
: m_screenHeight{600}, m_screenWidth{800}
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    else
    {
        // create window
        m_window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, 0);
        if (m_window == nullptr)
        {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
        else
        {
            surface = SDL_GetWindowSurface(m_window);
        }

        // initialize the renderer
        renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr)
        {
            std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        }
    }
}

IO::~IO()
{
    // handle window, renderer
    if(renderer)
        SDL_DestroyRenderer(renderer);
    if(m_window)
        SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void IO::clearScreen()
{
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
    SDL_RenderClear(renderer);
}

void IO::drawRectangle(int pX1, int pY1, int pX2, int pY2, enum Color pieceColor)
{
    Uint8 r = 0, g = 0, b = 0;

    switch (pieceColor)
    {
        case RED: r = 255; break;
        case GREEN: g = 255; break;
        case BLUE: b = 255; break;
        case CYAN: g = 255; b = 255; break;
        case MAGENTA: r = 255; b = 255; break;
        case YELLOW: r = 255; g = 255; break;
        case WHITE: r = 255; g = 255; b = 255; break;
        case GREY: r = 128; g = 128; b = 128; break;
        default: break;  // Black
    }

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect rect = {pX1, pY1, pX2 - pX1, pY2 - pY1};
    SDL_RenderFillRect(renderer, &rect);
}

void IO::updateScreen()
{
    SDL_RenderPresent(renderer);
}
