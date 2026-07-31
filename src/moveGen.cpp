#include <iostream>
#include "move.h"
#include "moveGen.h"
#include "Attacks.h"

void moveGen::generateKnightMoves(const Board &board, Board::Square square, std::vector<Move> &moves){
    uint64_t friendly; 
    uint64_t enemy;
    if(board.sideToMove==Board::Color::White){
        friendly=board.getWhiteOccupancy();
        enemy=board.getBlackOccupancy();
    }else{
        friendly=board.getBlackOccupancy();
        enemy=board.getWhiteOccupancy();
    }

    uint64_t moveBoard=Attacks::generateKnightAttacks(square, friendly, enemy);
    for(int i=0; i<64; i++){
        if((moveBoard & (1ULL << i))!=0){
            Move m;
            m.from=square;
            m.to=static_cast<Board::Square>(i);
            m.piece=Board::PieceType::Knight;
            moves.push_back(m);
        }
    }
}

void moveGen::generateKingMoves(const Board &board, Board::Square square, std::vector<Move> &moves){
    uint64_t friendly;
    uint64_t enemy;
    if(board.sideToMove==Board::Color::White){
        friendly=board.getWhiteOccupancy();
        enemy=board.getBlackOccupancy();
    }else{
        friendly=board.getBlackOccupancy();
        enemy=board.getWhiteOccupancy();
    }

    uint64_t moveBoard=Attacks::generateKingAttacks(square, friendly, enemy);
    for(int i=0; i<64; i++){
        if((moveBoard & (1ULL << i))!=0){
            Move m;
            m.from=square;
            m.to=static_cast<Board::Square>(i);
            m.piece=Board::PieceType::King;
            moves.push_back(m);
        }
    }
}

void moveGen::generateRookMoves(const Board &board, Board::Square square, std::vector<Move> &moves){
    uint64_t friendly; 
    uint64_t enemy;
    if(board.sideToMove==Board::Color::White){
        friendly=board.getWhiteOccupancy();
        enemy=board.getBlackOccupancy();
    }else{
        friendly=board.getBlackOccupancy();
        enemy=board.getWhiteOccupancy();
    }

    uint64_t moveBoard=Attacks::generateRookAttacks(square, friendly, enemy);
    for(int i=0; i<64; i++){
        if((moveBoard & (1ULL << i))!=0){
            Move m;
            m.from=square;
            m.to=static_cast<Board::Square>(i);
            m.piece=Board::PieceType::Rook;
            moves.push_back(m);
        }
    }
}

void moveGen::generateBishopMoves(const Board &board, Board::Square square, std::vector<Move> &moves){
    uint64_t friendly; 
    uint64_t enemy;
    if(board.sideToMove==Board::Color::White){
        friendly=board.getWhiteOccupancy();
        enemy=board.getBlackOccupancy();
    }else{
        friendly=board.getBlackOccupancy();
        enemy=board.getWhiteOccupancy();
    }

    uint64_t moveBoard=Attacks::generateBishopAttacks(square, friendly, enemy);
    for(int i=0; i<64; i++){
        if((moveBoard & (1ULL << i))!=0){
            Move m;
            m.from=square;
            m.to=static_cast<Board::Square>(i);
            m.piece=Board::PieceType::Bishop;
            moves.push_back(m);
        }
    }
}

void moveGen::generateQueenMoves(const Board &board, Board::Square square, std::vector<Move> &moves){
    uint64_t friendly; 
    uint64_t enemy;
    if(board.sideToMove==Board::Color::White){
        friendly=board.getWhiteOccupancy();
        enemy=board.getBlackOccupancy();
    }else{
        friendly=board.getBlackOccupancy();
        enemy=board.getWhiteOccupancy();
    }

    uint64_t moveBoard=Attacks::generateQueenAttacks(square, friendly, enemy);
    for(int i=0; i<64; i++){
        if((moveBoard & (1ULL << i))!=0){
            Move m;
            m.from=square;
            m.to=static_cast<Board::Square>(i);
            m.piece=Board::PieceType::Queen;
            moves.push_back(m);
        }
    }
}

void moveGen::generatePawnMoves(const Board &board, Board::Square square, std::vector<Move> &moves){
    uint64_t friendly;
    uint64_t enemy;
    
    if(board.sideToMove==Board::Color::White){
        friendly=board.getWhiteOccupancy();
        enemy=board.getBlackOccupancy();
    }else{
        friendly=board.getBlackOccupancy();
        enemy=board.getWhiteOccupancy();
    }
    uint64_t occupied=friendly|enemy;
    uint64_t singlePush=Attacks::generatePawnPush(board.sideToMove, square, occupied);
    uint64_t doublePush=Attacks::generatePawnDoublePush(board.sideToMove, square, occupied);
    uint64_t captures=Attacks::generatePawnAttacks(board.sideToMove, square, enemy);
    
    uint64_t moveBoard=singlePush|doublePush|captures;
    for(int i=0; i<64; i++){
        if((moveBoard & (1ULL << i))!=0){
            Move m;
            m.from=square;
            m.to=static_cast<Board::Square>(i);
            m.piece=Board::PieceType::Pawn;
            m.capture=(captures & (1ULL << i)) != 0;
            moves.push_back(m);

        }
    }
}