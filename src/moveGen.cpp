#include<iostream>
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
            m.capture=true;
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
            m.capture=true;
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
            m.capture=true;
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
            m.capture=true;
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
            m.capture=true;
            moves.push_back(m);
        }
    }
}