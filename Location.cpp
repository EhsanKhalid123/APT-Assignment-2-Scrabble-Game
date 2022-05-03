#include <Location.h>
#include "Board.cpp"

Location::Location(int x, int y){
    this->x = x;
    this->y = y;
}

void Location::setRow(int x){
    this->x = x;
}

int Location::getRow(){
    return x;
}

int Location::getCol(){
    return y;
}