#include "Menu.cpp"
#include "TileBag.cpp"

//Testing purpose
// #include "GameEngine.h"
// #include "TestTile.cpp"
// #include "TestNode.cpp"
// #include "TestLinkedList.cpp"
// #include "TestPlayer.cpp"

#define EXIT_SUCCESS    0

int main(void) {

   std::cout << "Welcome to Scrabble!" << std::endl;
   std::cout << "--------------------" << std::endl;

   Menu* mainMenu = new Menu();
   mainMenu->mainMenu();

   // GameEngine* game = new GameEngine();
   // std::string input = "place Done";
   // char a = input[6];
   // std::cout<<"A[6]: "<<a;
   // std::string input;
   // std::cout<<"> ";
   // getline(std::cin, input);

   // if(input == "place Done"){
   //    std::cout<<"Yes";
   // }
   // else{
   //    std::cout<<"No";
   // }

   // std::cout<<input.substr(0,5);
   
   // TestTile* testTile = new TestTile('A', 1);
   // Tile* tile = new Tile('B', 2);
   // TestNode* testNode = new TestNode(tile, nullptr);
   // TestLinkedList* sll = new TestLinkedList();
   // TestPlayer* player1 = new TestPlayer();
   return EXIT_SUCCESS;
}
