#include "Tile.h"

/* Tile Class Constructor */
Tile::Tile(Letter letter, Value value){
    this->letter = letter;
    this->value = value;
}

/* Gets the Tile Score Value */   
int Tile::getValue(){
    return value;
}
   
/* Gets the Tile Letter */   
char Tile::getLetter(){
    return letter;
}

/* Sets the Tile Score Value */   
void Tile::setValue(Value value){
    this->value = value;
}

/* Sets the Tile Letter */ 
void Tile::setLetter(Letter letter){
    this->letter = letter;
}

