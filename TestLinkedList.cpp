#include <iostream>
#include "LinkedList.h"

class TestLinkedList{
    public:
        TestLinkedList(){
            std::cout<<"<<<<<<<< Testing NodeList >>>>>>>>"<<std::endl;
            //4 Tiles
            Tile* tile1 = new Tile('P', 1);
            Tile* tile2 = new Tile('Q', 2);
            Tile* tile3 = new Tile('R', 3);
            Tile* tile4 = new Tile('S', 4);

            //singly linked list
            LinkedList* sll = new LinkedList();

            //Tiles added as 1, 2, 3, 4
            sll->add_front(tile2);
            sll->add_back(tile3);
            sll->add_front(tile1);
            sll->add_back(tile4);

            //display as 1, 2, 3, 4
            sll->display();

        //     //Printing 2nd Tile Data
        //     std::cout<<"2nd Letter: "<<sll->get(1)->getLetter()<<"\n2nd Value: "<<sll->get(1)->getValue()<<std::endl;

        //     //1 and 4 deleted
        //     sll->remove_front();
        //     sll->remove_back();

        //     //Length: 2
        //     std::cout<<"Length: "<<sll->size()<<std::endl;

        //     //2 and 3 displayed
        //     sll->display();

        //     //3 deleted
        //     sll->remove(1);

        //     //2 displayed
        //     sll->display();
        }
};