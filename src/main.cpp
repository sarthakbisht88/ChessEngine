#include <iostream>
#include <vector>

#include "Board.h"
#include "Attacks.h"
#include "Move.h"
#include "moveGen.h"


void testAttack(const std::string& name, uint64_t attacks)
{
    std::cout << "\n=== " << name << " ===\n";
    Attacks::printBitboard(attacks);
}

int main(){

    Board board;
    std::cout << " -----------------------------\n";

    
    
    std::cout << " -----------------------------\n";
    return 0;
}





// checking knight attacks
    // uint64_t attack=Attacks::generateKnightAttacks(Board::Square::B2);
    // Attacks::printBitboard(attack);

    // checking king attacks
    // uint64_t attack=Attacks::generatePawnPush(Board::Color::White, Board::Square::E4);
    // Attacks::printBitboard(attack);
    // uint64_t attack=Attacks::generateQueenAttacks(Board::Square::G4);
    // Attacks::printBitboard(attack);

    
    // board.setStartingPosition();
    // board.printBoard();

// board.sideToMove = Board::Color::White;

// // Place one white knight on B1
// board.setPiece(Board::Color::White,
//                Board::PieceType::Knight,
//                Board::Square::B1);

// std::vector<Move> moves;

// moveGen::generateKnightMoves(board, Board::Square::B1, moves);

// std::cout << "Generated moves: " << moves.size() << '\n';

// for (const Move& m : moves) {
//     std::cout << static_cast<int>(m.from)
//               << " -> "
//               << static_cast<int>(m.to)
//               << '\n';
// }