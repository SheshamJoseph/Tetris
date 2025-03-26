#include "../include/Board.hpp"

Board::Board()
{
    initBoard();
}

Board::~Board()
{

}

void Board::initBoard()
{
    for(int i=0; i<BOARD_WIDTH; ++i)
    {
        for(int j=0; j<BOARD_HEIGHT; ++j)
        {
            m_board[i][j] = BoardState::POS_FREE;
        }
    }
}

bool Board::isFreeCell(int x, int y)
{
    return m_board[x][y] == BoardState::POS_FREE;
}

int Board::getXPosInPixels(int x)
{
    /* Returns the horizontal position of the block given like parameter in pixels */
    return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (x * BLOCK_SIZE));
}

int Board::getYPosInPixels(int y)
{
    /* Returns the horizontal position of the block given like parameter in pixels */
    return ((SCREEN_HEIGHT - (BLOCK_SIZE * BOARD_HEIGHT)) + (y *BLOCK_SIZE));
}
