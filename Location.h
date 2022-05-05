#ifndef ASSIGN2_LOCATION_H
#define ASSIGN2_LOCATION_H
#include <iostream>

class Location{
    public:
        Location(int x, int y);
        void setRow(int x);
        void setCols(int y);

        int getRow();
        int getCol();
    private:
        int x,y;
};
#endif //ASSIGN2_LOCATION_H