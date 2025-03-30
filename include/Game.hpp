#pragma once

#include "Board.hpp"
#include "Piece.hpp"
#include "IO.hpp"
#include <iostream>
#include <time.h>
#include <memory>

class Game
{
private:
    /* data */
    IO m_io;
    SDL_Event e;
    Board m_board;
    // Piece* m_piece;
    std::unique_ptr<Piece> m_piece;

    // int m_screenHeight;
    // int m_screenWidth;
    PieceType m_nextPieceType;
    int m_nextPiecePosX;
    int m_nextPiecePosY;
    int m_nextPieceRotation;

    bool quit;
    void drawBoard();
    // void drawRectangle(int pX1, int pY1, int pX2, int pY2, enum Color pC);  /* IO::drawRectangle() */
    void initGame();
    void drawPiece(int x, int y/*, PieceType type*/);   /* IO::drawPiece() */
    int getRand(int a, int b);

public:
    int m_piecePosX;
    int m_piecePosY;
    int m_pieceRotation;
    PieceType m_pieceType;

    Game();
    ~Game();
    bool tick();
    // void createNewPiece();
};

