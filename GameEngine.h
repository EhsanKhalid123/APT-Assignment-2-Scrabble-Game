#ifndef ASSIGN2_GAMEENGINE_H
#define ASSIGN2_GAMEENGINE_H

#include <iostream>
#include "Player.h"
#include "LinkedList.h"
#include "Board.h"
#include "TileBag.h"
#include "Location.h"

class GameEngine{
    public:
        //Default Constructor
        GameEngine();
        GameEngine(bool enableEnhancement);
        
        //De-constructor
        ~GameEngine();
        
        //Constructor for New Game
        GameEngine(Player* player1, Player* player2, bool enableEnhancement);

        GameEngine(Player* player1, Player* player2, Player* player3, Player* player4, bool enableEnhancement);
        
        //Handles Game Functioning
        void gameStarts();
        void gameStartsEnhancement();
        
        //Load Game from saved file
        void loadGame(std::string* savedData);
        void loadGameEnhancement(std::string* savedData);
        
        //Handles the Ending of Game
        void gameEnds(Player* player1, Player* player2);
        void gameEnds(Player* player1, Player* player2, Player* player3, Player* player4);

        //Validates Input
        bool checkInputforPlacing(std::string input, LinkedList* hand);
        
        //Validates Rows
        bool checkRow(std::string input);

        //Validates Cols
        bool checkCol(char col);

        //Validates String
        bool checksString(std::string input);
        
        //Validates Letters present in Hand
        bool checksLetterinHand(char c, LinkedList* hand);
        
        //Validates Coordinates
        bool checkBoardCoordinates(std::string input);
        
        //Convert Char value to Integer
        int convertChartoInt(char c);
        
        //Handles game functioning
        bool playerPrompt(Player* player1, Player* player2);
        bool playerPrompt(Player* player1, Player* player2, Player* player3, Player* player4);
       
       //Return Tiles from Players hands
        Tile* getTileFromHand(char tileLetter, Player* player);
        
        //Checks for file
        bool checkFileExists(std::string input);
        
        //Converts Integer to Character
        char convertInttoChar(int i);

        // Checks for Input word from Dictionary/Word file 
        bool checkWord(std::string input);
        
        //Handles Game Quitting
        void gameQuits();

        //Handles Game Saving
        void gameSaves();

    private:
        TileBag* tileBag;
        Board* newBoard;
        Player* player1;
        Player* player2;
        Player* player3;
        Player* player4;
        bool gameEnd = false;
        bool gameSave = false;
        bool gameQuit = false;
        bool playerOneChance;
        bool playerTwoChance;
        bool playerThreeChance;
        bool playerFourChance;
        bool enableEnhancement;
        bool errorMsg = false;
};

#endif // ASSIGN2_GAMEENGINE_H