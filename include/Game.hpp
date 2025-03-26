#pragma once

#include "Board.hpp"
#include "Piece.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <time.h>
#include <memory>

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
    // Piece* m_piece;
    std::unique_ptr<Piece> m_piece;

    int m_screenHeight;
    int m_screenWidth;
    PieceType m_nextPieceType;
    int m_nextPiecePosX;
    int m_nextPiecePosY;
    int m_nextPieceRotation;

    bool quit {false};
    void drawBoard();
    void drawRectangle(int pX1, int pY1, int pX2, int pY2, enum Color pC);
    void initGame();
    void drawPiece(int x, int y/*, PieceType type*/);
    int getRand(int a, int b);

public:
    int m_piecePosX;
    int m_piecePosY;
    int m_pieceRotation;
    PieceType m_pieceType;

    Game();
    ~Game();
    bool tick();
    void createNewPiece();
};

