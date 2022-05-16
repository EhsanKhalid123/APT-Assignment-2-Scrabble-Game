#include "Menu.h"
#include <iostream>
#include <istream>
#include <fstream>

#include <algorithm>
#include <cctype>

Menu::Menu(){}
    
    
void Menu::mainMenu(){
    std::cout << "" << std::endl;
    std::cout << "Menu" << std::endl;
    std::cout << "----" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits (Show student information)" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "> "; std::cin >> userMenuInput;
    if (userMenuInput == 1){
        if (!std::cin.eof()){
            newGameMenu(); 
        }
    } else if (userMenuInput == 2){
        loadGameMenu();
    } else if (userMenuInput == 3){
        creditsMenu();
    }else if (userMenuInput == 4){
        std::cout << "" << std::endl;
        std::cout << "Goodbye" << std::endl;
    }

}

void Menu::checkForLower (std::string &playerName, std::string playerNumber) {
        for(std::string::iterator pName = playerName.begin(); pName != playerName.end(); ++pName) {
            while(islower(*pName)){
                if (!std::cin.eof()){
                    std::cout << "" << std::endl;
                    std::cout << "Please Enter Only Uppercase Characters!" << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "Enter a name for "<< playerNumber << " (uppercase characters only)" << std::endl;
                    std::cout << "> "; std::cin >> playerName;        
                }     
            }
        }
}

void Menu::newGameMenu(){
    std::cout << "" << std::endl;
    std::cout << "Starting a New Game" << std::endl;
    
    std::cout << "" << std::endl;
    //Player Name Prompt
    std::cout << "Enter a name for Player 1 (uppercase characters only)" << std::endl;
    std::cout << "> "; std::cin >> playerName;  
    checkForLower(playerName, "Player 1");

    //Initialising a hand for a player
    LinkedList* hand1 = new LinkedList();
    Player* player1 = new Player(playerName, 1, 0, hand1);

    std::cout << "" << std::endl;

    //Player Name Prompt
    std::cout << "Enter a name for Player 2 (uppercase characters only)" << std::endl;
    std::cout << "> "; std::cin >> playerName2;  
    checkForLower(playerName2, "Player 2");

    //Initialising a hand for a player
    LinkedList* hand2 = new LinkedList();
    Player* player2 = new Player(playerName2, 2, 0, hand2);

    std::cout << "" << std::endl;
    std::cout << "Let's Play!" << std::endl;

    GameEngine* gameEngine = new GameEngine(player1, player2);
    gameEngine->gameStarts();


    // These will be used later to display the names of the person who has the turn
    std::cout << "" << std::endl;
    std::cout << player1->getPlayerName() << std::endl;
    std::cout << player2->getPlayerName() << std::endl;
   
}

void Menu::loadGameMenu(){
    std::cout << "" << std::endl;
    std::cout << "Enter the filename from which to load a game" << std::endl;
    std::cout << "> "; std::cin >> fileName;
    std::string str;
    int counter = 0;

    // LinkedList* loadData = new LinkedList();
    std::string data[9];
    std::ifstream loadFile(fileName);

    if (!loadFile.fail()){
        while (!loadFile.eof()){
            std::getline(loadFile, str);
            //player 1 Name
            if (counter<9){
                data[counter] = str;
            }
            ++counter;
        }
        std::cout << "" << std::endl;
        std::cout << "Scrabble game successfully loaded" << std::endl;
        GameEngine* savedGameEngine = new GameEngine();
        savedGameEngine->loadGame(data);
        
    }
    else{
        std::cout<<"Cannot Open File"<<std::endl;
    }

    


}

void Menu::creditsMenu(){

    std::cout << "" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Name: Peter Mikhail" << std::endl;
    std::cout << "Student ID: s3843409" << std::endl;
    std::cout << "Email: s3843409@student.rmit.edu.au" << std::endl;

    std::cout << "" << std::endl;
    std::cout << "Name: Ehsan Khalid" << std::endl;
    std::cout << "Student ID: s3838975" << std::endl;
    std::cout << "Email: s3838975@student.rmit.edu.au" << std::endl;

    std::cout << "" << std::endl;
    std::cout << "Name: Preet Choudhary" << std::endl;
    std::cout << "Student ID: s3811259" << std::endl;
    std::cout << "Email: s3811259@student.rmit.edu.au" << std::endl;

    std::cout << "" << std::endl;
    std::cout << "Name: Warnakulasuriya Thamel" << std::endl;
    std::cout << "Student ID: s3863813" << std::endl;
    std::cout << "Email: s3863813@student.rmit.edu.au" << std::endl;
    std::cout << "----------------------------------" << std::endl;

    mainMenu();
}