#ifndef ASSIGN2_PLAYERS_H
#define ASSIGN2_PLAYERS_H
#include <string>

class Players {
public:

    Players(int playerNo);
    Players(Players &other);
    ~Players();
    
    /**
     * Return the player name
     */
    std::string getPlayerName();

private:
    std::string playerName;

};

#endif // ASSIGN2_PLAYERS_H