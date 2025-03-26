#include "../include/Piece.hpp"

// I, O, T, S, Z, J, L,
std::array<std::array<int, 5>, 5> shapes[7] = {
    // I-shape
    {{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }},
    // O-shape
    {{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    }},
    // T-shape
    {{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    }},
    // S-shape
    {{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    }},
    // Z-shape
    {{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
    }},
    // J-shape
    {{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    }},
    // L-shape
    {{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    }}
};

// Define 7 positions, one for each piece
std::array<int, 2> initialPositions[7] = {
    {-2, -3}, // I-shape
    {-3, -3}, // O-shape
    {-2, -3}, // T-shape
    {-2, -3}, // S-shape
    {-3, -3}, // Z-shape
    {-4, -2}, // J-shape
    {-2, -2}  // L-shape
};

Piece::Piece(PieceType pieceType)
    : m_pieceType{pieceType}, m_pieceRotation{0}
{
    setShape(pieceType);
}

void Piece::setShape(PieceType pieceType)
{
    m_pieceShape = shapes[static_cast<int>(pieceType)];
}

PieceType Piece::getType() const
{
    return m_pieceType;
}

int Piece::getRotation() const
{
    return m_pieceRotation;
}

int Piece::getXInitialPosition() const
{
    return initialPositions[static_cast<int>(m_pieceType)][0];
}

int Piece::getYInitialPosition() const
{
    return initialPositions[static_cast<int>(m_pieceType)][1];
}

bool Piece::isFilledBlock(int x, int y)
{
    return m_pieceShape[x][y];
}
