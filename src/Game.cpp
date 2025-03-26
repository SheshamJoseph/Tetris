#include "../include/Game.hpp"
#include <assert.h>

Game::Game()
    : m_screenHeight{400}, m_screenWidth{400}, quit{false}  // Initialize quit
{
    // initialize SDL window
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        // create window
        m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, 0);
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
        
        initGame();
    }
}

Game::~Game()
{
    // handle window, renderer
    if(renderer)
        SDL_DestroyRenderer(renderer);
    if(m_window)
        SDL_DestroyWindow(m_window);
    SDL_Quit();
}

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
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
    SDL_RenderClear(renderer);

    drawBoard();
    // drawPiece()
    // Present the updated screen
    SDL_RenderPresent(renderer); 


    return !quit;  // Return whether the game should keep running
}

void Game::drawRectangle(int pX1, int pY1, int pX2, int pY2, enum Color pC)
{
    Uint8 r = 0, g = 0, b = 0;

    switch (pC)
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

void Game::drawBoard()
{
    // Draw boundaries of the board
    int m_x1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH/2)) - 1;
    int m_x2 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH/2));
    int m_y = m_screenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

    // assert vertical margin is not small
    assert(m_y > MIN_VERTICAL_MARGIN);
    drawRectangle((m_x1 - BOARDLINE_WIDTH), m_y, m_x1, (m_screenHeight - 1), Color::BLUE);
    drawRectangle((m_x2 - BOARDLINE_WIDTH), m_y, m_x2, (m_screenHeight - 1), Color::BLUE);

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
                drawRectangle((m_x1 + i * BLOCK_SIZE),
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
                drawRectangle((m_pixelX + i * BLOCK_SIZE),
                                    (m_pixelY + j * BLOCK_SIZE),
                                    ((m_pixelX + i * BLOCK_SIZE) + BLOCK_SIZE - 1),
                                    ((m_pixelY + j * BLOCK_SIZE) + BLOCK_SIZE - 1),
                                    color
                                    );
            }
        }
    }
}
