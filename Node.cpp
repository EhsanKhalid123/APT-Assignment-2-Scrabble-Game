#include "Node.h"

/* Node Class Constructor */
Node::Node(Tile* tile, Node* next, Node* prev) {
   this->tile = tile;
   this->next = next;
   this->prev = prev;
}

/* De-constructor for Node Class */
Node::~Node(){
    delete tile;
}