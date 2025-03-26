#pragma once

#include <array>

enum class PieceType {
    I, O, T, S, Z, J, L,
};

class Piece {
private:
    PieceType m_pieceType;
    int m_pieceRotation;
    std::array<std::array<int, 5>, 5> m_pieceShape;
    std::array<std::array<int, 2>, 1> m_pieceInitialPosition;

    void setShape(PieceType type);

public:
    // Piece();
    // ~Piece();
    Piece(PieceType type);
    PieceType getType() const;
    // int getX() const;
    // int getY() const;
    int getRotation() const;
    // void move(int dx, int dy);
    void rotate();
    int getXInitialPosition() const;
    int getYInitialPosition() const;
    bool isFilledBlock(int x, int y);

};
