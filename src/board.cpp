#include<iostream>
#include "Board.h"

Board::Board(){
    for(int i=0; i<2; i++){
        for(int j=0; j<6 ;j++){
            bitboards[i][j]=0;
        }
    }

    sideToMove=Color::White;
    moveNumber=0;
    halfMoveClock=0;
    enPassantSquare=Square::None;
    castlingRights=0;
}

void Board::setPiece(Color color, PieceType pieceType, Square square){
    bitboards[static_cast<int>(color)][static_cast<int>(pieceType)] |= (1ULL << static_cast<int>(square));
    // static_cast is used to convert enum to int and 1ULL is basically "1" unsigned long long integer 
}

// void Board::setStartingPosition(setPiece()){
//     setPiece(Color::White, PieceType::Rook, Square::B1);
//     setPiece(Color::White, PieceType::Knight, Square::C1);
//     setPiece(Color::White, PieceType::Bishop, Square::D1);
//     setPiece(Color::White, PieceType::Queen, Square::E1);
//     setPiece(Color::White, PieceType::King, Square::F1);
// }

void Board::printBoard() const{
    const char notations[2][6]={
                {'P', 'R', 'N', 'B', 'Q', 'K'}, 
                {'p', 'r', 'n', 'b', 'q', 'k'}
        };
    
    for(int rank=7; rank>=0; rank--){
        for(int file=0; file<8; file++){
            int square = rank*8 + file;
            bool found=false;
            for(int color=0; color<2 && !found;color++){
                for(int piece=0; piece<6; piece++){
                    if(bitboards[color][piece] & (1ULL<<square)){
                        std::cout << notations[color][piece] << " ";
                        found=true;
                        break;
                    }
                }
            }
            if(!found){
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}