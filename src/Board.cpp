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
