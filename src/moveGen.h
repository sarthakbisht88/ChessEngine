#pragma once
#include <cstdint>
#include "board.h"
#include "Move.h"
#include <vector>

namespace moveGen{
    void generateKnightMoves(const Board &board, Board::Square square, std::vector<Move> &move);
    void generateKingMoves(const Board &board, Board::Square square, std::vector<Move> &move);

    void generatePawnMoves(const Board &board, Board::Square square, std::vector<Move> &move);

    void generateRookMoves(const Board &board, Board::Square square, std::vector<Move> &move);
    void generateBishopMoves(const Board &board, Board::Square square, std::vector<Move> &move);
    void generateQueenMoves(const Board &board, Board::Square square, std::vector<Move> &move);
}