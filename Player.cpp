#include "Player.h"
#include <iostream>
#include <istream>
#include <fstream>

Player::Player(std::string playerName, int playerNumber, int score, LinkedList* hand){

    //Player initialised with Name, Player Number, Score and a LinkedList for his Player's hand
    this->playerName = playerName;
    this-> playerNumber = playerNumber;
    this->scores = score;
    this->hand = hand; 

}

Player::Player(Player &other){
    this->playerName = other.playerName;
    this->playerNumber = other.playerNumber;
}

Player::~Player(){

}

//Getters and Setter for Name, Player's Number, Score and Player's Hand

std::string Player::getPlayerName(){
    return playerName;
}

void Player::setPlayerName(std::string playerName){
    this->playerName = playerName;
}

int Player::getPlayerNumber(){
    return playerNumber;
}

void Player::setPlayerNumber(int playerNumber){
    this->playerNumber = playerNumber;
}

int Player::getPlayerScore(){
    return scores;
}

void Player::setPlayerScore(int score){
    this->scores = score;
}

LinkedList* Player::getPlayerHand(){
    return hand;
}

void Player::setPlayerHand(LinkedList* hand){
    this->hand = hand;
}