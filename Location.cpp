#include "Location.h"

/* Constructor for Location Class */
Location::Location(int x, int y){
    this->x = x;
    this->y = y;
}

/* Sets Row Location */
void Location::setRow(int x){
    this->x = x;
}

/* Gets Row Location */
int Location::getRow(){
    return x;
}

/* Gets Location For Column */
int Location::getCol(){
    return y;
}