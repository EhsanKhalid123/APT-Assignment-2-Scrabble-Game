#include "Players.h"

#include <iostream>
#include <istream>
#include <fstream>

Players::Players(int playerNumber, std::string playerName){

    this->playerName = playerName;
    this-> playerNumber = playerNumber;

}

Players::Players(Players &other){
    this->playerName = other.playerName;
    this->playerNumber = other.playerNumber;
}

Players::~Players(){

}


std::string Players::getPlayerName(){

    return playerName;
}

void Players::setPlayerNumber(int playerNumber){

    this->playerNumber = playerNumber;

}

int Players::getPlayerNumber(){

    return playerNumber;
}