#include <iostream>
#include "LinkedList.h"

class TestLinkedList{
    public:
        TestLinkedList(){
            std::cout<<"<<<<<<<< Testing LinkedList >>>>>>>>"<<std::endl;
            //4 Tiles
            Tile* tile1 = new Tile('P', 1);
            Tile* tile2 = new Tile('Q', 2);
            Tile* tile3 = new Tile('R', 3);
            Tile* tile4 = new Tile('S', 4);
            Tile* tile5 = new Tile('T', 5);
            Tile* tile6 = new Tile('U', 6);
            Tile* tile7 = new Tile('V', 7);


            //singly linked list
            LinkedList* sll = new LinkedList();

            //Tiles added as 1, 2, 3, 4
            sll->add_back(tile3);
            sll->add_front(tile2);
            sll->add_back(tile4);
            sll->add_front(tile1);
            sll->add_back(tile5);
            sll->add_back(tile6);
            sll->add_back(tile7);

            // sll->remove_front();

            //display as P, Q, R, S
            sll->display();

            sll->remove(0);

            sll->display();

            //Length 4
            // std::cout<<sll->size()<<std::endl;

            //Printing 2nd Tile Data
            // std::cout<<"2nd Letter: "<<sll->get(1)->getLetter()<<"\n2nd Value: "<<sll->get(1)->getValue()<<std::endl;

            //Removes 2nd Tile
            // sll->remove(1);
            // sll->display();

            //Clear the LinkedList
            // sll->clear();
            // std::cout<<sll->size()<<std::endl;
            
            //1 and 4 deleted
            // sll->remove_front();
            // sll->remove_back();
            // sll->display();

            //Length 2
            // std::cout<<sll->size()<<std::endl;


            //Withdraw front
            // std::cout<<"Letter withdrawn: "<<sll->withdraw_front()->getLetter()<<std::endl;
            // sll->display();
            // std::cout<<sll->size()<<std::endl;

            //

        }
};