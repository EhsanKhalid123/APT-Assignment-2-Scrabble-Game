#include "TileBag.h"
#include <fstream>
#include <iostream>
#include <random>

TileBag::TileBag(){
    std::ifstream tilesFile("ScrabbleTiles.txt");
    Letter letter;
    Value value;

    // Get Letter and Value from the file and Convert it into a Tile
    if (!tilesFile.fail()){
        while (tilesFile >> letter >> value)
        {
            //Creating a new Tile
            Tile* tile = new Tile(letter, value);
            //Adding the Tile to Temporary Bag
            tempTileBag->add_back(tile);
            ++size;
        }
    }

    std::random_device randomSeed;
    std::uniform_int_distribution<int> uniform_dist(0, tempTileBag->size());
    int i = 0;
    while (i < tempTileBag->size()) {     

        // Picks a random tile from the temporary Tile bag!!!!
        int randTileIndex = uniform_dist(randomSeed);
        if (tempTileBag->get(randTileIndex) != nullptr) {
            
            // Creates a new Tile based on the random picked tile from tempTileBag
            Tile* tile = new Tile(*tempTileBag->get(randTileIndex));

            // Adds the tile to the actual tileBag
            tileBag->add_back(tile);

            // Removes the tiles from temporary tile bag
            tempTileBag->remove(randTileIndex);
            ++i;
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

void TileBag::clear(){
    tileBag->clear();
    size = 0;
}
