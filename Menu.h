#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H
#include <map>
#include "GameEngine.h"
#include "Player.h"

class Menu {
public:

    Menu();

    void mainMenu();
    
    void enhancementMenu();

    void newGameMenu(bool enableEnhancement);

    void loadGameMenu();

    void creditsMenu();

    void helpMenu();

    void enhancements();

    void Quit();

    static void checkForLower (std::string &playerName, std::string playerNumber);

private:
    int userMenuInput;
    std::string playerName;
    std::string playerName2;
    std::string fileName;
    std::string enhancement;
    bool enableEnhancement;
};

#endif // ASSIGN2_MENU_H