#pragma once
#include <cstdint>
#include "Board.h"

namespace Attacks{

    uint64_t generateKnightAttacks(Board::Square square);
    void printBitboard(uint64_t bitboard);
} 