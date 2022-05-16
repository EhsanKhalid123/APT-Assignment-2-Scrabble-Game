#include "TileBag.h"
#include <fstream>
#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include <bits/stdc++.h>

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

    std::vector<int> numbers;

    for(int i=0; i<tempTileBag->size(); i++){      
        numbers.push_back(i);
    }   

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    for(int i=0; i<tempTileBag->size(); i++){       
        tileBag->add_back(tempTileBag->get(numbers[i]));
    }   
}

void TileBag::shuffle(Tile* tileBagArr, int length){
    std::vector<int> numbers;

    for(int i=0; i<100; i++)       // add 0-99 to the vector
        numbers.push_back(i);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    for(int i=0; i<99; i++)        // print the first 40 randomly sorted numbers
        std::cout << numbers[i] << std::endl;

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
