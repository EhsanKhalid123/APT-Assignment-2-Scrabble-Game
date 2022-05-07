#include "TileBag.h"
#include "LinkedList.h"
#include <fstream>
#include<iostream>

TileBag::TileBag(){
    std::ifstream tilesFile("ScrabbleTiles.txt");
    Letter letter;
    Value value;

    if (!tilesFile.fail()){
        while (tilesFile >> letter >> value)
        {
            //Creating a new Tile
            Tile* tile = new Tile(letter, value);

            //Adding the Tile to Bag
            tileBag->add_back(tile);
            ++size;
        }
    }
}

//Tiles added at the end of Linked List
void TileBag::addTile(Tile* tile){
    tileBag->add_back(tile);
    ++size;
}

// void TileBag::display(){
//     std::cout<<tileBag->get(0)->getLetter()<<"-"<<tileBag->get(0)->getValue();
//     for (int i = 0; i < tileBag->size(); ++i){
//         std::cout<<", "<<tileBag->get(i)->getLetter()<<"-"<<tileBag->get(i)->getValue();
//     }
    
// }

//Withdraw Tiles from the front
Tile* TileBag::getTile(){
    //Check whether TileBag is empty or not
    if (tileBag->size() == 0){
        return nullptr;
    }
    --size;
    return tileBag->withdraw_front();
}

//Get tiles from index
Tile* TileBag::get(int index){
    if (tileBag->size() == 0){
        return nullptr;
    }
    return tileBag->get(index);
}
