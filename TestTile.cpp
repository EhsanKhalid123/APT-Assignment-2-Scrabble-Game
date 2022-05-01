#include <iostream>
#include "Tile.h"

class TestTile{
    public:
        TestTile(Letter letter, Value value){
            Tile* tile = new Tile(letter, value);
            std::cout<<"<<<<<<<< Testing Tile >>>>>>>>"<<std::endl;
            std::cout<<"Letter is: "<<tile->getLetter()<<std::endl;
            std::cout<<"Value is: "<<tile->getValue()<<std::endl;
            
            tile->setLetter('Z');
            tile->setValue(26);

            std::cout<<"After Setting new Letter and Value"<<std::endl;
            std::cout<<"Letter is: "<<tile->getLetter()<<std::endl;
            std::cout<<"Value is: "<<tile->getValue()<<"\n"<<std::endl;
        }
};