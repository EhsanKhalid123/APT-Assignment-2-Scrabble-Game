#include "LinkedList.h"

//Constructor
LinkedList::LinkedList() {
   this->head = nullptr;
   this->tail = nullptr;
   // TODO
}

// LinkedList::LinkedList(LinkedList& other) {
//    head = nullptr;

//     for(int i = 0; i < other.size(); ++i){
//         Tile* tile = new Tile(*other.get(i));
//         add_back(tile);
//     }
// }

LinkedList::~LinkedList(){
   clear();
}

//Returns size of LinkedList
int LinkedList::size(){
   return length;
}

//Gets Tile from a particular index
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

//Adds Tile at front
void LinkedList::add_front(Tile* tile){
   Node* node;
   //if list is empty
   if (head == nullptr){
      node = new Node(tile, nullptr, nullptr);
      head = node;
      tail = node;
      ++length;
   }
   else{
      node = new Node(tile, head, nullptr);
      head = node;
      head->prev = nullptr;
      ++length;
   }
}

//Adds Tile at the back
void LinkedList::add_back(Tile* tile){
   Node* node;
   if (head == nullptr){
      node = new Node(tile, nullptr, nullptr);
      head = node;
      tail = node;
   }
   else{
      Node * upto = this->head;
 
        while (upto->next != nullptr) 
        {
            upto = upto->next;
        }
        upto->next = new Node(tile, nullptr, upto);
        this->tail = upto->next;
   }
   ++length;
}

//Deletes Tiles from front
void LinkedList::remove_front(){
   Node* tmp = head;
   if (head != nullptr){
      head = head->next;
      head->prev = nullptr;
      tmp->next = nullptr;
      --length;
   }
   else{
      std::cout<<"List Empty"<<std::endl;
   }
}

//Deletes Tiles from Back
void LinkedList::remove_back(){
   if (head != nullptr){
      Node* node = tail->prev;
      node->next = nullptr;
      tail = node;
      --length;
   }
   else{
      std::cout<<"List Empty"<<std::endl;
   }
}

//Return Tiles from front and deletes it
Tile* LinkedList::withdraw_front(){
   if (head != nullptr){
      Tile* head1 = head->tile;
      remove_front();
      return head1;
   }
   else{
      std::cout<<"No Tiles Left"<<std::endl;
      return nullptr;
   }
}

//Removes the Tile from a particular index
void LinkedList::remove(int index){

   //If index is larger than size
   // if(index >= length){
   //    std::cout<<"Invalid Input"<<std::endl;
   // }
   // else{
   //    if(index == 0){
   //       remove_front();
   //    }
      
   //    else if(index == length-1){
   //       remove_back();
   //    }

   //    else{
   //       // Node* upto = head;
   //       // for(int i = 0; i < index; ++i){
   //       //    upto = upto->next;
   //       // }
   //       // std::cout<<upto->tile->getLetter()<<std::endl;

   //       // Node* nodeBefore = upto->prev;
   //       // std::cout<<"Node Before: "<<upto->prev->tile->getLetter()<<std::endl;
   //       // Node* nodeAfter = upto->next;
   //       // std::cout<<"Node After: "<<nodeAfter->tile->getLetter()<<std::endl;
   //       // nodeBefore->next = nodeAfter;
   //       // nodeAfter->prev = nodeBefore;
   //       // // upto->next=nullptr;
   //       // // upto->prev=nullptr;

   //       // // Note that removeFront and removeBack methods also subtract
   //       // // size by one in its own implementation
   //       // --length;
   //       // std::cout<<"Line 156"<<std::endl;
   //       Node *upto = head;
   //       std::cout<<"Line 45"<<std::endl;
   //       for(int i = 0; i < index; ++i){
   //             upto = upto->next;
   //       }
   //       Node* nodeBefore = (upto->prev);
   //       nodeBefore->next = upto->next;

   //       Node* to_be_deleted = upto;
   //       Node* nodeAfter = upto->next;
   //       delete to_be_deleted;

   //       nodeAfter->prev = nodeBefore;

   //       // Note that removeFront and removeBack methods also subtract
   //       // size by one in its own implementation
   //       length--;
   //    }
   // }
   if (index >= 0 && index < size()) {
      if (head != nullptr) {
         int counter = 0;
         Node* current = head;
         Node* prevNode = nullptr;

         while (counter != index) {
            ++counter;
            prevNode = current;
            current = current->next;
         }

         if (prevNode == nullptr) {
            remove_front();
         }
         else if (current->next == nullptr) {
            remove_back();
         }
         else {
            prevNode->next = current->next;
            current->next->prev = prevNode;
            delete current;
            --length;
         }
      }
   }
}

//Clears the LinkedList
void LinkedList::clear(){
   while (head != nullptr){
      remove_front();
   }
}

//Displays LinkedList
void LinkedList::display(){
   Node* start = head;
   while (start != nullptr){
      std::cout<<"Tile "<<": "<<start->tile->getLetter()<<std::endl;
      start = start->next;
   }
}
