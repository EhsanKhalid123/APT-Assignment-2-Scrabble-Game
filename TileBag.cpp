#include "TileBag.h"
#include "LinkedList.h"
#include <fstream>



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
        }
    }
    

}

//Tiles added at the end of Linked List
void TileBag::addTile(Tile* tile){
    tileBag->add_back(tile);
}

//Withdraw Tiles from the front
Tile* TileBag::getTile(){
    //Check whether TileBag is empty or not
    if (tileBag->size() == 0){
        return nullptr;
    }
    return tileBag->withdraw_front();
}