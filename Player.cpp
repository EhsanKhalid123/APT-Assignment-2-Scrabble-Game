#include "Player.h"
#include <iostream>
#include <istream>
#include <fstream>

/* Player Class Constructor */
Player::Player(std::string playerName, int playerNumber, int score, LinkedList* hand){

    //Player initialised with Name, Player Number, Score and a LinkedList for his Player's hand
    this->playerName = playerName;
    this-> playerNumber = playerNumber;
    this->scores = score;
    this->hand = hand; 
}

/* Copy Constructor for Player */
Player::Player(Player &other){
    this->playerName = other.playerName;
    this->playerNumber = other.playerNumber;
}

/* De-contructor for Player */
Player::~Player(){

}

/* Gets player name */
std::string Player::getPlayerName(){
    return playerName;
}

/* Sets player name */
void Player::setPlayerName(std::string playerName){
    this->playerName = playerName;
}

/* Gets player number */
int Player::getPlayerNumber(){
    return playerNumber;
}

/* Sets player number */
void Player::setPlayerNumber(int playerNumber){
    this->playerNumber = playerNumber;
}

/* Gets player score */
int Player::getPlayerScore(){
    return scores;
}

/* Sets player score */
void Player::setPlayerScore(int score){
    this->scores = score;
}

/* Gets player hand */
LinkedList* Player::getPlayerHand(){
    return hand;
}

/* Sets number of passes counter */
void Player::setPassCounter(int passCounter){
    this->passCounter = passCounter;
}

/* Gets number of passes done */
int Player::getPassCounter(){
    return this->passCounter;
}

/* Sets player hand */
void Player::setPlayerHand(LinkedList* hand){
    this->hand = hand;
}

/* Shows the current tiles in players hand */
void Player::TilesonPlayersHands(Player* player){
    std::cout<<player->getPlayerHand()->get(0)->getLetter()<<"-"<<player->getPlayerHand()->get(0)->getValue();
    for (int i = 1; i < 7; ++i){
        std::cout<<", "<<player->getPlayerHand()->get(i)->getLetter()<<"-"<<player->getPlayerHand()->get(i)->getValue();
    }
    std::cout<<"\n"<<std::endl;
}