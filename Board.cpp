#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H
#include "Board.h"
#include <iostream>

Board::Board(){
    for (int i = 0; i < ENV_DIM; ++i){
        for (int j = 0; j < ENV_DIM; ++j){
            env.push_back(nullptr);
        }
    }
}

Board::Board(Board &other){

}

Board::~Board(){

}

void Board::printBoard(){
    //Printing Rows
    std::cout<<"    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15"<<std::endl;
    std::cout<<"   ----------------------------------------------------------------"<<std::endl;

    //Printing Columns and Blank Spaces no Tile is Present there
    for (int i = 0; i < ENV_DIM; ++i){
        std::cout<<cols[i];
        if (env[i] == nullptr){
            for (int j = 0; j < ENV_DIM+2; ++j){
                std::cout<<" |  ";
            }
            std::cout<<""<<std::endl;
        }
        else{
            for (int j = 0; j < ENV_DIM+2; ++j){
                std::cout<<" |  "<<env[i];
            }
            std::cout<<""<<std::endl;
        }
    }
}

#endif // ASSIGN2_BOARD_H