#include <iostream>
#include "Board.h"
#include "Attacks.h"

int main(){

    Board board;
    std::cout << " -----------------------------\n";
    board.setStartingPosition();
    board.printBoard();
    // uint64_t attacks=Attacks::generateKnightAttacks(Board::Square::E4);
    std::cout << " -----------------------------\n";
    return 0;
}