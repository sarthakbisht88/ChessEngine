#include <iostream>
#include "Board.h"

int main(){

    Board board;
    std::cout << " -----------------------------\n";
    board.setStartingPosition();
    board.printBoard();
    std::cout << " -----------------------------\n";
    return 0;
}