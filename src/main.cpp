#include <iostream>
#include "Board.h"
#include "Attacks.h"

int main(){

    Board board;
    std::cout << " -----------------------------\n";

    board.setStartingPosition();
    board.printBoard();

    uint64_t attack=Attacks::generateKnightAttacks(Board::Square::B2);
    Attacks::printBitboard(attack);
    
    std::cout << " -----------------------------\n";
    return 0;
}