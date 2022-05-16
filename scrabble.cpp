#include "Menu.h"
#include "TileBag.h"

#define EXIT_SUCCESS    0

// Main Method
int main(void) {

   // Initial Welcome Screen Print Statements
   std::cout << "Welcome to Scrabble!" << std::endl;
   std::cout << "--------------------" << std::endl;

   // Runs the Main Menu Method
   Menu* mainMenu = new Menu();
   mainMenu->mainMenu();  


   return EXIT_SUCCESS;
}
