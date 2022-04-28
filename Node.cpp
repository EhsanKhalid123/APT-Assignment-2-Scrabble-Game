
#include "Node.h"

Node::Node(Tile* tile, Node* next) {

   this->tile = new Tile(*tile);
   this->next = next;
  
}

Node::Node(Node& other) {

   this->tile = new Tile(*other.tile);
   this->next = other.next;

}

Node::~Node()
{
    delete tile;
}