/*
This file handles the key stroke events and rendering of the screen
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
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

class IO 
{
private:
    int m_screenHeight;
    int m_screenWidth;
    SDL_Window* m_window;   
    SDL_Surface* surface;
    SDL_Renderer* renderer;

public:
    IO();
    ~IO();
    void clearScreen();
    void drawRectangle(int pX1, int pY1, int pX2, int pY2, enum Color pieceColor);
    void updateScreen();


};
