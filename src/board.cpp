#include <iostream>
#include "Board.h"

Board::Board(){
    for(int i=0; i<2; i++){
        for(int j=0; j<6 ;j++){
            bitboards[i][j]=0;
        }
    }
    sideToMove=Color::White;
    moveNumber=1;
    halfMoveClock=0;
    enPassantSquare=Square::None;
    castlingRights=0;
}

void Board::setPiece(Color color, PieceType pieceType, Square square){
    bitboards[static_cast<int>(color)][static_cast<int>(pieceType)] |= (1ULL << static_cast<int>(square));
    // static_cast is used to convert enum to int and 1ULL is basically "1" unsigned long long integer 
}

void Board::printBoard() const{
    const char notations[2][6]={
                {'P', 'R', 'N', 'B', 'Q', 'K'}, 
                {'p', 'r', 'n', 'b', 'q', 'k'}
        };
    
    for(int rank=7; rank>=0; rank--){
        for(int file=0; file<8; file++){
            int square = rank*8 + file;
            bool found=false;
            for(int color=0; color<2 && !found; color++){
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

void Board::clearBoard(){
    for(int i=0; i<2; i++){
        for(int j=0; j<6 ;j++){
            bitboards[i][j]=0;
        }
    }
    sideToMove=Color::White;
    moveNumber=1;
    halfMoveClock=0;
    enPassantSquare=Square::None;
    castlingRights=0;
}

void Board::setStartingPosition(){
    clearBoard();
    setPiece(Color::White, PieceType::Rook, Square::A1);
    setPiece(Color::White, PieceType::Rook, Square::H1);
    setPiece(Color::White, PieceType::Knight, Square::B1); 
    setPiece(Color::White, PieceType::Knight, Square::G1);
    setPiece(Color::White, PieceType::Bishop, Square::C1);    
    setPiece(Color::White, PieceType::Bishop, Square::F1);
    setPiece(Color::White, PieceType::Queen, Square::D1);   
    setPiece(Color::White, PieceType::King, Square::E1);

    for(int file=0; file<8; file++){    // NOTE: because file maintains horizontal lines (2nd rank)
        setPiece(Color::White, PieceType::Pawn, static_cast<Square>(file+8));    // 8,9,10,11,12,13,14,15
    }

    setPiece(Color::Black, PieceType::Rook, Square::A8);
    setPiece(Color::Black, PieceType::Rook, Square::H8);
    setPiece(Color::Black, PieceType::Knight, Square::B8);
    setPiece(Color::Black, PieceType::Knight, Square::G8);
    setPiece(Color::Black, PieceType::Bishop, Square::C8);    
    setPiece(Color::Black, PieceType::Bishop, Square::F8);
    setPiece(Color::Black, PieceType::Queen, Square::D8);   
    setPiece(Color::Black, PieceType::King, Square::E8);

    for(int file=0; file<8; file++){    // NOTE: because file maintains horizontal lines (7th rank)
        setPiece(Color::Black, PieceType::Pawn, static_cast<Square>(file+48));    // 48,49,50,51,52,53,54,55
    }

}

void Board::removePiece(Color color, PieceType pieceType, Square square){
    bitboards[static_cast<int>(color)][static_cast<int>(pieceType)] &= ~(1ULL <<static_cast<int>(square));
}

void Board::movePiece(Color color, PieceType pieceType, Square fromSquare, Square toSquare){
    removePiece(color, pieceType, fromSquare);
    setPiece(color, pieceType, toSquare);
}

bool Board::hasPiece(Color color, PieceType pieceType, Square square) const{
    return (bitboards[static_cast<int>(color)][static_cast<int>(pieceType)] & (1ULL << static_cast<int>(square))) != 0;
}

uint64_t Board::getWhiteOccupancy() const{
    uint64_t occupancyBoard=0;
    for(int i=0 ; i<6; i++){
        occupancyBoard |= bitboards[0][i];
    }
    return occupancyBoard;
}

uint64_t Board::getBlackOccupancy() const{
    uint64_t occupancyBoard=0;
    for(int i=0 ; i<6; i++){
        occupancyBoard |= bitboards[1][i];
    }
    return occupancyBoard;
}

uint64_t Board::getOccupancy() const{
    return getBlackOccupancy() | getWhiteOccupancy();
}