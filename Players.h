#ifndef ASSIGN2_PLAYERS_H
#define ASSIGN2_PLAYERS_H
#include <string>

class Players {
public:

    Players(int playerNumber, std::string playerName);
    Players(Players &other);
    ~Players();
    
    /**
     * Return the player name
     */
    std::string getPlayerName();

    void setPlayerNumber(int playerNumber);

    int getPlayerNumber();

private:
    std::string playerName;
    int playerNumber;

};

#endif // ASSIGN2_PLAYERS_H