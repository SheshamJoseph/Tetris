#pragma once

// #include "Piece.hpp"
#include <array>

// Constants
constexpr int BOARDLINE_WIDTH = 6;
constexpr int BLOCK_SIZE = 16;
constexpr int BOARD_POSITION = 320;
constexpr int BOARD_WIDTH = 10;
constexpr int BOARD_HEIGHT = 20;
constexpr int MIN_VERTICAL_MARGIN = 20;
constexpr int MIN_HORIZONTAL_MARGIN = 20;
constexpr int PIECE_BLOCKS = 5;
constexpr int SCREEN_HEIGHT = 400;
constexpr int SCREEN_WIDTH = 400;

// Enum for board state
enum class BoardState 
{
    POS_FREE,
    POS_FILLED
};

class Board
{
private:
    BoardState m_board[BOARD_HEIGHT][BOARD_WIDTH]; // Fixed order
    // Piece currentPiece;
    // Piece nextPiece;
    void initBoard();  // Should be public if called outside

public:
    Board();
    ~Board();
    bool isFreeCell(int x, int y);
    int getXPosInPixels(int x);
    int getYPosInPixels(int y);
};
