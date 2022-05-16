#include <iostream>
#include "Board.h"

char columns[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};


Board::Board(){

    // this->size = 0;
    for (int i = 0; i < ENV_DIM; ++i){
        // Tile* tile1 = new Tile('A',1);
        std::vector<Tile*> row;
        for (int j = 0; j < ENV_DIM; ++j){
            row.push_back(nullptr);
        }
        this->board.push_back(row);
    }
}

Board::Board(Board &other){

}

Board::~Board(){

}

void Board::updateBoard(Tile* tile, int row, int col){
    this->board[col-1][row] = tile;
}

void Board::printBoard(){
    //Printing Rows
    std::cout<<"    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14"<<std::endl;
    std::cout<<"   ------------------------------------------------------------"<<std::endl;

    //Printing Columns and Blank Spaces no Tile is Present there
    for (int i = 0; i < (int)this->board.size(); ++i){
        std::cout << columns[i];
        for (int j = 0; j < (int)this->board[i].size(); ++j){
            if (this->board[i][j] == nullptr){
                std::cout<<" |  ";
            }
            else{
                std::cout<<" | "<< (char)this->board[i][j]->getLetter();
            }
        }
        std::cout<<" |"<<std::endl;
    }
}
