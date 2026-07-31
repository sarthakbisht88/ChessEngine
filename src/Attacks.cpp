#include <iostream>
#include "Attacks.h"
#include "Board.h"

uint64_t Attacks::generateKnightAttacks(Board::Square square, uint64_t friendly, uint64_t enemy){
    uint64_t bitboardAttacks=0;
    int rank = static_cast<int>(square)/8;
    int file = static_cast<int>(square)%8;

    const int rankOffsets[8]={2,2,1,1,-2,-2,-1,-1};
    const int fileOffsets[8]={1,-1,2,-2,1,-1,2,-2};
    for(int i=0; i<8; i++){
        int newRank=rank+rankOffsets[i];
        int newFile=file+fileOffsets[i];
        if(newRank>=0 && newFile>=0 && newRank<8 && newFile<8){
            int newSquare=newRank*8+newFile;
            if (friendly & (1ULL << newSquare))continue;
            bitboardAttacks |= (1ULL << newSquare);
        }
    }
    return bitboardAttacks;
}

void Attacks::printBitboard(uint64_t bitboard){
    for(int rank=7; rank>=0; rank--){
        for(int file=0; file<8; file++){
            int square=8*rank + file;
            if((bitboard & (1ULL<<square)) != 0){
                std::cout << "1 ";
            }else{
                std::cout << ". ";
            }
        }
        std::cout << "\n" ;
    }
}

uint64_t Attacks::generateKingAttacks(Board::Square square, uint64_t friendly, uint64_t enemy){
    uint64_t bitboardAttacks=0;
    int rank=static_cast<int> (square)/8;
    int file=static_cast<int> (square)%8;

    const int rankOffsets[8]={1,-1,0,0,1,1,-1,-1};
    const int fileOffsets[8]={0,0,1,-1,1,-1,-1,1};
    for(int i=0; i<8; i++){
        int newRank=rank+rankOffsets[i];
        int newFile=file+fileOffsets[i];
        if(newRank>=0 && newFile>=0 && newRank<8 && newFile<8){
            int newSquare=newRank*8+newFile;
            if (friendly & (1ULL << newSquare))continue;
            bitboardAttacks |= (1ULL << newSquare);
        }
    }
    return bitboardAttacks;
}

uint64_t Attacks::generatePawnAttacks(Board::Color color, Board::Square square, uint64_t enemy){
    uint64_t bitboardAttacks=0;
    int rank = static_cast<int>(square)/8;
    int file = static_cast<int>(square)%8;

    int dir;
    if(color==Board::Color::White){
        dir=1;
    }else{
        dir=-1;
    }
    const int fileOffsets[2]={1, -1};
    int newRank=rank+dir;
    for(int i=0; i<2; i++){
        int newFile=file+fileOffsets[i];
        int newSquare=newRank*8 + newFile;
        if(newRank>=0 && newFile>=0 && newRank<8 && newFile<8){
            if(enemy & (1ULL << newSquare))
            bitboardAttacks |= (1ULL << newSquare);
        }
    }
    return bitboardAttacks;
}

uint64_t Attacks::generatePawnPush(Board::Color color, Board::Square square, uint64_t occupied){
    uint64_t bitboardAttacks=0;
    int rank = static_cast<int>(square)/8;
    int file = static_cast<int>(square)%8;
    int dir;
    if(color==Board::Color::White){
        dir=1;
    }else{
        dir=-1;
    }
    int newRank=rank+dir;
    int newSquare=newRank*8 + file;
    if(newRank>=0 && file>=0 && newRank<8 && file<8){
        if((occupied & (1ULL << newSquare)) == 0){
            bitboardAttacks |= (1ULL << newSquare);
        }
    }
    return bitboardAttacks;
}

uint64_t Attacks::generatePawnDoublePush(Board::Color color, Board::Square square, uint64_t occupied){
    uint64_t bitboardAttacks=0;
    int rank = static_cast<int>(square)/8;
    int file = static_cast<int>(square)%8;
    int dir;
    if(color==Board::Color::White){
        dir=1;
    }else{
        dir=-1;
    }
    if(rank!=1 && dir==1 || rank!=6 && dir==-1){
        return bitboardAttacks;
    }

    uint64_t oneStep = generatePawnPush(color, square, occupied);
    if(oneStep == 0){
        return bitboardAttacks;
    }

    int newRank=rank+2*dir;
    int newSquare=newRank*8 + file;
    if(newRank>=0 && file>=0 && newRank<8 && file<8){
        if((occupied & (1ULL << newSquare)) == 0){ 
            bitboardAttacks |= (1ULL << newSquare);
        }
    }
    return bitboardAttacks;
}

uint64_t Attacks::generateRookAttacks(Board::Square square, uint64_t friendly, uint64_t enemy){
    uint64_t bitboardAttacks=0;
    int rank = static_cast<int>(square)/8;
    int file = static_cast<int>(square)%8;
    uint64_t occupied=friendly|enemy;
    const int rankDir[4]={1, -1, 0, 0};
    const int fileDir[4]={0, 0, 1, -1};
    for(int i=0; i<4; i++){
        int newRank=rank;
        int newFile=file;
        while(true){
            
            newRank+=rankDir[i];
            newFile+=fileDir[i];
            if(newRank<0 || newFile<0 || newRank>7 || newFile>7){
                break;
            }
            int newSquare=8*(newRank) + newFile;
            if((occupied & (1ULL << newSquare))==0){
                bitboardAttacks |= (1ULL << newSquare);
                continue;
            }
            if((friendly & (1ULL << newSquare))!=0){
                break;
            }
            if((enemy & (1ULL << newSquare))!=0){
                bitboardAttacks |= (1ULL << newSquare);
                break;
            }
            
        }
    }
    return bitboardAttacks;
}

uint64_t Attacks::generateBishopAttacks(Board::Square square, uint64_t friendly, uint64_t enemy){
    uint64_t bitboardAttacks=0;
    int rank = static_cast<int>(square)/8;
    int file = static_cast<int>(square)%8;
    uint64_t occupied=friendly|enemy;
    const int rankDir[4]={1, -1, 1, -1};
    const int fileDir[4]={1, -1, -1, 1};

    for(int i=0; i<4; i++){
        int newRank=rank;
        int newFile=file;
        while(true){
            
            newRank+=rankDir[i];
            newFile+=fileDir[i];
            if(newRank<0 || newFile<0 || newRank>7 || newFile>7){
                break;
            }
            int newSquare=8*(newRank) + newFile;
            if((occupied & (1ULL << newSquare))==0){
                bitboardAttacks |= (1ULL << newSquare);
                continue;
            }
            if((friendly & (1ULL << newSquare))!=0){
                break;
            }
            if((enemy & (1ULL << newSquare))!=0){
                bitboardAttacks |= (1ULL << newSquare);
                break;
            }
        }
    }
    return bitboardAttacks;
}

uint64_t Attacks::generateQueenAttacks(Board::Square square, uint64_t friendly, uint64_t enemy){
    return generateBishopAttacks(square, friendly, enemy) | generateRookAttacks(square, friendly, enemy);
}