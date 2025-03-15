#pragma once

#include "Board.hpp"
#include <SDL2/SDL.h>
#include <iostream>

enum Color
{
    BLACK,
    RED,
    GREEN,
    BLUE,
    CYAN,
    MAGENTA,
    YELLOW,
    WHITE,
    GREY,
    COLOR_MAX
}; // Colors

class Game
{
private:
    /* data */
    SDL_Window* m_window;   
    SDL_Surface* surface;
    SDL_Event e;
    SDL_Renderer* renderer;

    Board m_board;

    int m_screenHeight;
    int m_screenWidth;

    bool quit {false};
    bool isFreeBlock(int x, int y);
    void drawBoard();
    void drawRectangle(int pX1, int pY1, int pX2, int pY2, enum Color pC);
    // void drawPiece(int x, int y, int piece, int rotation);

public:
    Game();
    ~Game();
    bool tick();
};

