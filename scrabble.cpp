
#include "LinkedList.h"
#include "Menu.h"
#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   std::cout << "Welcome to Scrabble!" << std::endl;
   std::cout << "--------------------" << std::endl;

   Menu* mainMenu = new Menu();
   mainMenu->mainMenu();

   return EXIT_SUCCESS;
}
