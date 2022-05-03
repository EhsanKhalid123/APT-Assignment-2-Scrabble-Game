#include <iostream>
#include "Player.h"
#include "LinkedList.h"
#include "Board.cpp"

class GameEngine{
    public:
        GameEngine();
        GameEngine(Player* player1, LinkedList* hand1, Player* player2, LinkedList* hand2);

        //Handles the Ending of Game
        void gameEnds(Player* player1, Player* player2);

    private:
};