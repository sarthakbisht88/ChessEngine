#pragma once
#include <cstdint>


class Board{
    public:

    Board();
    uint64_t bitboards[2][6];

    enum class Color{
        White, Black
    };

    enum class PieceType{
        Pawn, Rook, Knight, Bishop, Queen, King
    };

    enum class Square{
        A1, B1, C1, D1, E1, F1, G1, H1, 
        A2, B2, C2, D2, E2, F2, G2, H2, 
        A3, B3, C3, D3, E3, F3, G3, H3,
        A4, B4, C4, D4, E4, F4, G4, H4, 
        A5, B5, C5, D5, E5, F5, G5, H5,
        A6, B6, C6, D6, E6, F6, G6, H6, 
        A7, B7, C7, D7, E7, F7, G7, H7, 
        A8, B8, C8, D8, E8, F8, G8, H8,
        None
    };

    int halfMoveClock=0; // basically - counts and addresses 50-move situation
    int moveNumber=1;
    Color sideToMove;
    Square enPassantSquare;
    uint8_t castlingRights;

    void clearBoard();
    void printBoard() const;
    void setStartingPosition();

    void setPiece(Color color, PieceType pieceType, Square square);
    void removePiece(Color color, PieceType pieceType, Square square);
    void movePiece(Color color, PieceType pieceType, Square fromSquare, Square toSquare);
    bool hasPiece(Color color, PieceType pieceType, Square square) const;
};