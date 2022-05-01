
#include "Tile.h"

Tile::Tile(Letter letter, Value value){
    this->letter = letter;
    this->value = value;
}
   
int Tile::getValue(){
    return value;
}
   
char Tile::getLetter(){
    return letter;
}

void Tile::setValue(Value value){
    this->value = value;
}
void Tile::setLetter(Letter letter){
    this->letter = letter;
}
// Empty... for now?
