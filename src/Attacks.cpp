#include<iostream>
#include "Attacks.h"
#include "Board.h"

uint64_t Attacks::generateKnightAttacks(Board::Square square){
    uint64_t bitboardAttacks=0;
    int rank = static_cast<int>(square)/8;
    int file = static_cast<int>(square)%8;

    const int rankOffsets[8]={2,2,1,1,-2,-2,-1,-1};
    const int fileOffsets[8]={1,-1,2,-2,1,-1,2,-2};
    for(int i=0;i<8;i++){
        int newRank=rank+rankOffsets[i];
        int newFile=file+fileOffsets[i];
        if(newRank>=0 && newFile>=0 && newRank<8 && newFile<8){
            int newSquare=newRank*8+newFile;
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