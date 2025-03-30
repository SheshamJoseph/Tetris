#include "../include/Game.hpp"
#include <assert.h>

Game::Game()
    : quit{false}  // Initialize quit
{
    /* TODO: this is already done in IO::IO */       
    initGame();
}

Game::~Game()
{}

void Game::initGame()
{
    srand((unsigned int) time(NULL));
    // first piece 
    m_pieceType = static_cast<PieceType>(getRand(0, 6));
    m_piece = std::make_unique<Piece>(m_pieceType);
    m_pieceRotation = m_piece->getRotation();
    /* TODO: Need to figure out the initial positions of pieces*/ 
    m_piecePosX = (BOARD_WIDTH / 2) + m_piece->getXInitialPosition();
    m_piecePosY = m_piece->getYInitialPosition();

    // next piece
    m_nextPieceType = static_cast<PieceType>(getRand(0, 6));
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
    // Clear the screen
    /* TODO: call IO::clearScreen() */
    m_io.clearScreen();

    drawBoard();
    drawPiece(m_piecePosX, m_piecePosY);
    // Present the updated screen
    m_io.updateScreen();


    return !quit;  // Return whether the game should keep running
}

void Game::drawBoard()
{
    // Draw boundaries of the board
    int m_x1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH/2)) - 1;
    int m_x2 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH/2));
    int m_y = SCREEN_HEIGHT - (BLOCK_SIZE * BOARD_HEIGHT);

    // assert vertical margin is not small
    assert(m_y > MIN_VERTICAL_MARGIN);
    m_io.drawRectangle((m_x1 - BOARDLINE_WIDTH), m_y, m_x1, (SCREEN_HEIGHT - 1), Color::BLUE);
    m_io.drawRectangle((m_x2 - BOARDLINE_WIDTH), m_y, m_x2, (SCREEN_HEIGHT - 1), Color::BLUE);

    // assert horizontal margin is not small
    assert(m_x1 > MIN_HORIZONTAL_MARGIN);
    // Drawing blocks stored on the block
    m_x1 += 1;
    for(int i{0}; i<BOARD_WIDTH; ++i)
    {
        for(int j{0}; j<BOARD_HEIGHT; ++j)
        {
            if(m_board.isFreeCell(i, j))
            {
                m_io.drawRectangle((m_x1 + i * BLOCK_SIZE),
                                    (m_y + j * BLOCK_SIZE),
                                    ((m_x1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1),
                                    ((m_y + j * BLOCK_SIZE) + BLOCK_SIZE - 1),
                                    Color::GREY
                                    );
            }
        }
    }
}

int Game::getRand(int a, int b)
{
    /* 
    Returns a random number between a nd b inclusive 
    */
    return rand() % (b - a + 1) + a;
}

void Game::drawPiece(int x, int y /*, PieceType type*/)
{
    Color color;
    int m_pixelX = m_board.getXPosInPixels(x);
    int m_pixelY = m_board.getYPosInPixels(y);
    // traverse the matrix and color filled blocks
    for(int i{0}; i<PIECE_BLOCKS; ++i)
    {
        for(int j{0}; j<PIECE_BLOCKS; ++j)
        {
            if (m_piece->isFilledBlock(j, i))
            {
                int type = static_cast<int>(m_pieceType);
                color = static_cast<Color>(type + 1);
                m_io.drawRectangle((m_pixelX + i * BLOCK_SIZE),
                                    (m_pixelY + j * BLOCK_SIZE),
                                    ((m_pixelX + i * BLOCK_SIZE) + BLOCK_SIZE - 1),
                                    ((m_pixelY + j * BLOCK_SIZE) + BLOCK_SIZE - 1),
                                    color
                                    );
            }
        }
    }
}
