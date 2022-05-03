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