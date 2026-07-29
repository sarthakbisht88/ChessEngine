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
    // uint64_t attack=Attacks::generatePawnPush(Board::Color::White, Board::Square::E4);
    // Attacks::printBitboard(attack);

    uint64_t friendly = (1ULL << 0);
uint64_t enemy = 0;

uint64_t attacks = Attacks::generateBishopAttacks(
    static_cast<Board::Square>(0),
    friendly,
    enemy
);

Attacks::printBitboard(attacks);
    // uint64_t attack=Attacks::generateQueenAttacks(Board::Square::G4);
    // Attacks::printBitboard(attack);
    
    std::cout << " -----------------------------\n";
    return 0;
}