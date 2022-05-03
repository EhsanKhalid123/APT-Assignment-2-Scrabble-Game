#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H
#include "Board.h"
// #include "Tile.h"
#include <iostream>

Board::Board(){
    for (int i = 0; i < ENV_DIM; ++i){
        // Tile* tile1 = new Tile('A',1);
        std::vector<Tile*> row;
        env.push_back(row);
        for (int j = 0; j < ENV_DIM; ++j){
            env[i].push_back(nullptr);
        }
    }
}

Board::Board(Board &other){

}

Board::~Board(){

}

void Board::printBoard(){
    //Printing Rows
    std::cout<<"    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14"<<std::endl;
    std::cout<<"   ------------------------------------------------------------"<<std::endl;

    //Printing Columns and Blank Spaces no Tile is Present there
    for (int i = 0; i < ENV_DIM; ++i){
        std::cout<<cols[i];
        for (int j = 0; j < ENV_DIM; ++j){
            if (env[i][j] == nullptr){
                std::cout<<" |  ";
            }
            else{
                std::cout<<" | "<<env[i].at(j)->getLetter();;
            }
        }
        std::cout<<" |"<<std::endl;
    }
}

#endif // ASSIGN2_BOARD_H