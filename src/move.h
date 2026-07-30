#pragma once
#include "board.h"

struct Move{
    Board::Square from;
    Board::Square to;
    Board::PieceType piece;

    bool capture = false;
    bool promotion = false;
    bool castle = false;
    bool enPassant = false;

};