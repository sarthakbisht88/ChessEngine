#include <iostream>
#include "Board.h"
#include "Attacks.h"

int main(){

    Board board;
    std::cout << " -----------------------------\n";

    board.setStartingPosition();
    board.printBoard();

    // checking knight attacks
    // uint64_t attack=Attacks::generateKnightAttacks(Board::Square::B2);
    // Attacks::printBitboard(attack);

    // checking king attacks
    uint64_t attack=Attacks::generatePawnPush(Board::Color::White, Board::Square::E4);
    Attacks::printBitboard(attack);
    
    std::cout << " -----------------------------\n";
    return 0;
}