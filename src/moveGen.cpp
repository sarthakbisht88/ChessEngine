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
            int rank=i/8;
            bool isPromotion=(board.sideToMove==Board::Color::White && rank==7) || (board.sideToMove==Board::Color::Black && rank==0);
            if(isPromotion){
                Board::PieceType promotionPieces[4]={
                    Board::PieceType::Queen,
                    Board::PieceType::Rook,
                    Board::PieceType::Bishop,
                    Board::PieceType::Knight
                };
                for(Board::PieceType promotionPiece:promotionPieces){

                    Move m;
                    m.from = square;
                    m.to = static_cast<Board::Square>(i);
                    m.piece = Board::PieceType::Pawn;
                    m.capture = (captures & (1ULL << i)) != 0;
                    m.promotion = true;
                    m.promotionPiece = promotionPiece;

                    moves.push_back(m);
                }
            }else{
                Move m;
                m.from=square;
                m.to=static_cast<Board::Square>(i);
                m.piece=Board::PieceType::Pawn;
                m.capture=(captures & (1ULL << i)) != 0;
                moves.push_back(m);
            }
        }
    }
}

void moveGen::generateCastleMoves(const Board &board, Board::Square square, std::vector<Move> &moves){
    uint64_t occupancy=board.getOccupancy();

    if(board.sideToMove==Board::Color::White){
        if((board.castlingRights & board.WhiteKingside) && 
           (occupancy & ((1ULL << static_cast<int>(Board::Square::F1)) | (1ULL << static_cast<int>(Board::Square::G1)))) == 0) {
            Move m;
            m.from=square;
            m.to=Board::Square::G1;
            m.piece=Board::PieceType::King;
            m.castle=true;
            moves.push_back(m);
        }
        if((board.castlingRights & board.WhiteQueenside) && 
           (occupancy & ((1ULL << static_cast<int>(Board::Square::B1)) | (1ULL << static_cast<int>(Board::Square::C1)) | (1ULL << static_cast<int>(Board::Square::D1)))) == 0) {
            Move m;
            m.from=square;
            m.to=Board::Square::C1;
            m.piece=Board::PieceType::King;
            m.castle=true;
            moves.push_back(m);
        }
    } else {
        if((board.castlingRights & board.BlackKingside) && 
           (occupancy & ((1ULL << static_cast<int>(Board::Square::F8)) | (1ULL << static_cast<int>(Board::Square::G8)))) == 0) {
            Move m;
            m.from=square;
            m.to=Board::Square::G8;
            m.piece=Board::PieceType::King;
            m.castle=true;
            moves.push_back(m);
        }
        if((board.castlingRights & board.BlackQueenside) && 
           (occupancy & ((1ULL << static_cast<int>(Board::Square::B8)) | (1ULL << static_cast<int>(Board::Square::C8)) | (1ULL << static_cast<int>(Board::Square::D8)))) == 0) {
            Move m;
            m.from=square;
            m.to=Board::Square::C8;
            m.piece=Board::PieceType::King;
            m.castle=true;
            moves.push_back(m);
        }
    }    
}

