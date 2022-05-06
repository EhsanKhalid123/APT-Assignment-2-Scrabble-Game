#include <iostream>
#include "Board.h"
// #include "Tile.h"

Board::Board(){
    for (int i = 0; i < ENV_DIM; ++i){
        // Tile* tile1 = new Tile('A',1);
        std::vector<Tile*> row;
        for (int j = 0; j < ENV_DIM; ++j){
            row.push_back(nullptr);
        }
        board.push_back(row);
    }
}

Board::Board(Board &other){

}

Board::~Board(){

}

void Board::updateBoard(Tile* tile, int row, int col){
    board[col-1][row] = tile;
}

void Board::printBoard(){
    //Printing Rows
    std::cout<<"    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14"<<std::endl;
    std::cout<<"   ------------------------------------------------------------"<<std::endl;

    //Printing Columns and Blank Spaces no Tile is Present there
    for (int i = 0; i < board.size(); ++i){
        std::cout<<cols[i];
        for (int j = 0; j < board[i].size(); ++j){
            if (board[i][j] == nullptr){
                std::cout<<" |  ";
            }
            else{
                std::cout<<" | "<<board[i][j]->getLetter();
            }
        }
        std::cout<<" |"<<std::endl;
    }
}
