#include <iostream>
#include "Node.h"
class TestNode{
    public: 
        TestNode(Tile* tile, Node* next){
            Node* node = new Node(tile, next);
            std::cout<<"<<<<<<<< Testing Node >>>>>>>>"<<std::endl;
            std::cout<<"Node Letter: "<<node->tile->getLetter()<<"\nNode Value: "<<node->tile->getValue()<<"\nNode next: "<<node->next<<"\n"<<std::endl;
        }
};