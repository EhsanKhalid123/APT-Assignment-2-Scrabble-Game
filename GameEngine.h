#include <iostream>
#include "Player.h"
#include "LinkedList.h"
#include "Board.cpp"
#include "TileBag.h"
#include "Location.h"

class GameEngine{
    public:
        GameEngine();
        GameEngine(Player* player1, Player* player2);

        //Handles the Ending of Game
        void gameEnds(Player* player1, Player* player2);
        bool checkInputforPlacing(std::string input, LinkedList* hand);
        bool checkRow(std::string input);
        bool checkCol(char col);
        bool checksString(std::string input);
        bool checksLetterinHand(char c, LinkedList* hand);
        bool checkBoardCoordinates(std::string input);
        int convertChartoInt(char c);
        void playerPrompt(Player* player1, Player* player2);
        Tile* getTileFromHand(char tileLetter, Player* player);

    private:
        TileBag* tileBag;
        Board* newBoard;
};