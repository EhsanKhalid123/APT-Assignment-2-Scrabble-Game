
#include "LinkedList.h"
#include "Menu.h"
#include "TestTile.cpp"
#include "TestNode.cpp"
#include "TestLinkedList.cpp"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   std::cout << "Welcome to Scrabble!" << std::endl;
   std::cout << "--------------------" << std::endl;

   // Menu* mainMenu = new Menu();
   // mainMenu->mainMenu();
   
   TestTile* testTile = new TestTile('A', 1);
   Tile* tile = new Tile('B', 2);
   TestNode* testNode = new TestNode(tile, nullptr);
   
   // TestLinkedList* sll = new TestLinkedList();
   return EXIT_SUCCESS;
}
