#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H
#include "LinkedList.h"
#include "Tile.h"

class TileBag {
    public:

        TileBag();
        
        void addTile(Tile* tile);
        
        Tile* getTile();
               
        void shuffleArray(Tile* arr[], int n);
        
        Tile* get(int index);
        
        void clear();

        void shuffle(Tile* tileBagarr, int length);
    
        LinkedList* tempTileBag = new LinkedList();
        LinkedList* tileBag = new LinkedList();
        
        int size;

};

#endif // ASSIGN2_TILEBAG_H