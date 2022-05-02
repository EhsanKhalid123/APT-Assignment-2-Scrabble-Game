#include <iostream>
#include "Player.h"
#include "LinkedList.h"

class TestPlayer{
    //Testing Player Class
    public:
        TestPlayer(){
            //Created a New Player
            LinkedList* hand = new LinkedList();
            Player* player1 = new Player("Alice", 123, 5, hand);

            //Printing Player's Information
            std::cout<<"<<<<<<<< Testing Player >>>>>>>>"<<std::endl;
            std::cout<<"Name is: "<<player1->getPlayerName()<<std::endl;
            std::cout<<"ID is: "<<player1->getPlayerNumber()<<std::endl;
            std::cout<<"Score is: "<<player1->getPlayerScore()<<std::endl;
            // std::cout<<"Players Hand: "<<player1->getPlayerHand()<<std::endl;
        }
};