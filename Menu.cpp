#include "Menu.h"

#include <iostream>
#include <istream>
#include <fstream>

Menu::Menu(){

}
    
Menu::Menu(Menu& other){

}

Menu::~Menu(){

}
    
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
        newGameMenu();
        
    } else if (userMenuInput == 2){
        loadGameMenu();
    } else if (userMenuInput == 3){
        creditsMenu();
    }else if (userMenuInput == 4){
        std::cout << "" << std::endl;
        std::cout << "Goodbye" << std::endl;
        exit(0);
    }

}

void Menu::newGameMenu(){
    std::cout << "" << std::endl;
    std::cout << "Starting a New Game" << std::endl;

    std::cout << "" << std::endl;
    std::cout << "Enter a name for player 1 (uppercase characters only)" << std::endl;
    std::cout << "> "; std::cin >> playerName;

    std::cout << "" << std::endl;
    std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
    std::cout << "> "; std::cin >> playerName2;

    std::cout << "" << std::endl;
    std::cout << "Let's Play!" << std::endl;
    
}

void Menu::loadGameMenu(){
    std::cout << "" << std::endl;
    std::cout << "Enter the filename from which load a game" << std::endl;
    std::cout << "> "; std::cin >> fileName;

    std::cout << "" << std::endl;
    std::cout << "Scrabble game successfully loaded" << std::endl;
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