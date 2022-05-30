#include "Menu.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <cctype>

/* Menu Class Constructor */
Menu::Menu(){}
    
/* Displays Main Menu & Other Menus Based on User Input */
void Menu::mainMenu(){
    std::cout << "" << std::endl;
    std::cout << "Menu" << std::endl;
    std::cout << "----" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits (Show student information)" << std::endl;
    std::cout << "4. Help" << std::endl;
    std::cout << "5. Quit" << std::endl;
    std::cout << "" << std::endl;

/* Displays menu based on user input */
    std::cout << "> "; std::cin >> userMenuInput;
    if (userMenuInput == 1){
        newGameMenu(); 
    } else if (userMenuInput == 2){
        loadGameMenu();
    } else if (userMenuInput == 3){
        creditsMenu();
    } else if (userMenuInput == 4) {
        helpMenu();
    } else if (userMenuInput == 5){
        Quit();
    } else {
        std::cout << "" << std::endl;
        std::cout << "Please Enter Only Numbers 1 - 5 or the command \"help\"" << std::endl;
    }

}

/* Method to check for Lowercase user name input */
void Menu::checkForLower (std::string &playerName, std::string playerNumber) {

        if (playerName == "help") {
            std::cout << "◉ Please type your name using capital case" << std::endl;
        }

        for(std::string::iterator pName = playerName.begin(); pName != playerName.end(); ++pName) {
            // Loop if name is lowercase
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

/* New Game Menu */
void Menu::newGameMenu(){
    std::cout << "" << std::endl;
    std::cout << "Starting a New Game" << std::endl;
    
    std::cout << "" << std::endl;
    // Player 1 Name Prompt
    std::cout << "Enter a name for Player 1 (uppercase characters only)" << std::endl;
    std::cout << "> "; std::cin >> playerName;  
    checkForLower(playerName, "Player 1");

    // Initialising a hand for a player
    LinkedList* hand1 = new LinkedList();
    Player* player1 = new Player(playerName, 1, 0, hand1);
    std::cout << "" << std::endl;

    // Player 2 Name Prompt
    std::cout << "Enter a name for Player 2 (uppercase characters only)" << std::endl;
    std::cout << "> "; std::cin >> playerName2;  
    checkForLower(playerName2, "Player 2");

    // Initialising a hand for a player
    LinkedList* hand2 = new LinkedList();
    Player* player2 = new Player(playerName2, 2, 0, hand2);

    std::cout << "" << std::endl;
    std::cout << "Let's Play!" << std::endl;

    // Calls the Start Game Method to begin game
    GameEngine* gameEngine = new GameEngine(player1, player2);
    gameEngine->gameStarts();
 
}

/* Load Game Menu */
void Menu::loadGameMenu(){
    std::cout << "" << std::endl;
    std::cout << "Enter the filename from which to load a game" << std::endl;
    std::cout << "> "; std::cin >> fileName;
    std::string str;
    int counter = 0;

    // Loads file
    std::string data[9];
    std::ifstream loadFile(fileName);

    // Get data from file if file exists
    if (!loadFile.fail()){
        while (!loadFile.eof()){
            std::getline(loadFile, str);
            // Stores the data from file into an array
            if (counter<9){
                data[counter] = str;
            }
            ++counter;
        }
        std::cout << "" << std::endl;
        std::cout << "Scrabble game successfully loaded" << std::endl;

        // Calls load Game method to continue playing loaded game
        GameEngine* savedGameEngine = new GameEngine();
        savedGameEngine->loadGame(data);     
    }
    else {
        std::cout << "" << std::endl;
        std::cout<<"Cannot Open File"<<std::endl;
        mainMenu();
    }
}

/* Displays the Credits */
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

    // Displays Main Menu
    mainMenu();
}

void Menu::helpMenu(){
    std::cout << "" << std::endl;
    std::cout << "Please Enter Only Numbers From 1 - 5. Enter the number corressponding to each statement to select that option" << std::endl;
    std::cout << "Enter Number 1 to Start a New Game" << std::endl;
    std::cout << "Enter Number 2 to Load a Saved Game" << std::endl;
    std::cout << "Enter Number 3 to See the Credits" << std::endl;
    std::cout << "Enter Number 4 to See the Help Page" << std::endl;
    std::cout << "Enter Number 5 to Quit the Game" << std::endl;
    
    mainMenu();
}

void Menu::Quit (){
    std::cout << "" << std::endl;
    std::cout << "Goodbye" << std::endl;
}