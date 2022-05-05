
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList {
public:
   LinkedList();

   LinkedList(LinkedList &other);

   ~LinkedList();

   int size();

   Tile* get(int index);

   void add_front(Tile* data);
   
   void add_back(Tile* data);

   void remove_front();

   void remove_back();

   Tile* withdraw_front();

   void remove(int index);

   void clear();

   void display();

private:
   Node* head;
   Node* tail;
   int length = 0;
};

#endif // ASSIGN2_LINKEDLIST_H
