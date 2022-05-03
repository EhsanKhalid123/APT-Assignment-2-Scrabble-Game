#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H
#include "LinkedList.h"
#include "Tile.h"

class TileBag {
    public:
        TileBag();
        void addTile(Tile* tile);
        Tile* getTile();
        
    private:
        LinkedList* tileBag = new LinkedList();
};

#endif // ASSIGN2_TILEBAG_H