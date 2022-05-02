#include <iostream>
#include "Tile.h"

class TestTile{
    //Testing Tile Class
    public:
        TestTile(Letter letter, Value value){
            //Created a New Tile
            Tile* tile = new Tile(letter, value);

            //Displayed Tile
            std::cout<<"<<<<<<<< Testing Tile >>>>>>>>"<<std::endl;
            std::cout<<"Letter is: "<<tile->getLetter()<<std::endl;
            std::cout<<"Value is: "<<tile->getValue()<<std::endl;
            
            //Updated the Letter and Value
            tile->setLetter('Z');
            tile->setValue(26);

            //Displaying and confirming after Changing Values
            std::cout<<"After Setting new Letter and Value"<<std::endl;
            std::cout<<"Letter is: "<<tile->getLetter()<<std::endl;
            std::cout<<"Value is: "<<tile->getValue()<<"\n"<<std::endl;
        }
};