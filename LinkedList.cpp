#include "LinkedList.h"
#include <stdexcept>

LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}

LinkedList::LinkedList(LinkedList& other) {
   head = nullptr;

    for(int i = 0; i < other.size(); ++i){
        Tile* tile = new Tile(*other.get(i));
        add_back(tile);
    }
}

LinkedList::~LinkedList(){
   clear();
}

int LinkedList::size(){
   int length = 0;

      Node* current = head;
      while(current != nullptr){
         ++length;
         current = current->next;
      }
   return length;
}

Tile* LinkedList::get(int index){
   Tile* returnTile = nullptr;

    if(index >= 0 && index < size()){

        int counter = 0;
        Node* current = head;

        while(counter<index){
            ++counter;
            current = current->next;
        }

        returnTile = current->tile;

    }
    return returnTile;
}

void LinkedList::add_front(Tile* tile){
   Node* node = new Node(tile, nullptr);
   node->next = head;
   node->tile = tile;
   head = node;
}

void LinkedList::add_back(Tile* tile){
   Node* node = new Node(tile, nullptr);
   node->next = nullptr;
   node->tile = tile;

   if (head == nullptr){
      head = node;
   } else {
      Node* current = head;
      while (current->next != nullptr){
         current = current->next;
      }

      current->next = node;
   }
}

void LinkedList::remove_front(){
   if (head != nullptr){
      Node* toDelete = head;
      head = head->next;

      delete toDelete->tile;
      delete toDelete;
   }
}

void LinkedList::remove_back(){
   if (head != nullptr){
        Node* current = head;
        Node* prev = nullptr;
        while (current->next != nullptr){
            prev = current;
            current = current->next;
        }
        
        if (prev == nullptr){
            head = nullptr;
        }else {
            prev->next = nullptr;
        }

        delete current->tile;
        delete current;

    } else {
        throw std::runtime_error("Nothing to delete!");
    }
}

void LinkedList::remove(int index){
   Tile* returnTile = nullptr;

   if(index >= 0 && index < size()){

      int counter = 0;
      Node* current = head;

      while(counter<index){
         ++counter;
         current = current->next;
      }

      returnTile = current->tile;

   }
   delete returnTile;
}

void LinkedList::clear(){
   while (head != nullptr){
      remove_front();
   }
}