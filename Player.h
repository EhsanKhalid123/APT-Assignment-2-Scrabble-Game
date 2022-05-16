#ifndef ASSIGN2_Player_H
#define ASSIGN2_Player_H

#include <string>
#include "LinkedList.h"
#include "Location.h"

class Player {
public:

    Player(std::string playerName, int playerNumber, int score, LinkedList* hand);
    
    Player(Player &other);
    
    ~Player();
    
    std::string getPlayerName();

    void setPlayerName(std::string playerName);

    int getPlayerNumber();

    void setPlayerNumber(int playerNumber);

    int getPlayerScore();

    void setPlayerScore(int score);

    LinkedList* getPlayerHand();

    void setPlayerHand(LinkedList* hand);

    void setPassCounter(int passCounter);

    int getPassCounter();
    
    void addTile();

    void TilesonPlayersHands(Player* player);
private:
    std::string playerName;
    int playerNumber;
    int scores = 0;
    LinkedList* hand;
    int passCounter = 0;
};

#endif // ASSIGN2_Player_H