#pragma once
#include <cstdint>
#include "Board.h"

namespace Attacks{

    void printBitboard(uint64_t bitboard);
    
    uint64_t generateKnightAttacks(Board::Square square);
    uint64_t generateKingAttacks(Board::Square square);
    uint64_t generatePawnAttacks(Board::Color color, Board::Square square);
    uint64_t generatePawnPush(Board::Color color, Board::Square square);
    uint64_t generatePawnDoublePush(Board::Color color, Board::Square square);
    uint64_t generateRookAttacks(Board::Square square, uint64_t friendly, uint64_t enemy);
    uint64_t generateBishopAttacks(Board::Square square, uint64_t friendly, uint64_t enemy);
    uint64_t generateQueenAttacks(Board::Square square, uint64_t friendly, uint64_t enemy);
}