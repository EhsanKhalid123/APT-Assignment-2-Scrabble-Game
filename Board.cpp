#include <iostream>
#include "Board.h"

char columns[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};

/* Board Constructor */
Board::Board(){

    for (int i = 0; i < ENV_DIM; ++i){
        std::vector<Tile*> row;
        for (int j = 0; j < ENV_DIM; ++j){
            row.push_back(nullptr);
        }
        this->board.push_back(row);
    }
}

/* Board Copy Constructor */
Board::Board(Board &other){

}

/* Board De-constructor */
Board::~Board(){

}

/* Updates Board: Places tiles on Board */
void Board::updateBoard(Tile* tile, int row, int col){
    this->board[col-1][row] = tile;
}

/* Prints the Scrabble Board */ 
void Board::printBoard(){
    // Printing Rows
    std::cout<<"    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14"<<std::endl;
    std::cout<<"   ------------------------------------------------------------"<<std::endl;

    // Printing Columns and Blank Spaces no Tile is Present there
    for (int i = 0; i < (int)this->board.size(); ++i){
        std::cout << columns[i];
        for (int j = 0; j < (int)this->board[i].size(); ++j){
            if (this->board[i][j] == nullptr){
                std::cout<<" |  ";
            }
            else{
                // "\033[33m" <- This Here Colours the Tiles \033 is escape character, 33 is ASCII Code for Colour Yellow
                std::cout << " | " <<"\033[33m" << (char)this->board[i][j]->getLetter() << "\033[0m";
            }
        }
        std::cout<<" |"<<std::endl;
    }
}
