
#include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <limits>

Node::Node(int value, Node* next) :
   value(value),
   next(next)
{}

LinkedList::LinkedList() 
{
   // TODO

}

LinkedList::LinkedList(LinkedList& other) 
{
   // TODO
}

LinkedList::~LinkedList() {
   // TODO
}

int LinkedList::size() {
   int count = 0;
   Node* current = head;
   while(current != nullptr) {
      ++count;
      current = current->next;
   }
   return count;
}

int LinkedList::get(int index) {
   int count = 0;
   Node* current = head;
   // int returnValue = 0;
   int returnValue = std::numeric_limits<int>::min();
   if(index >= 0 && index < size()) {
      while(count < index) {
         ++count;
         current = current->next;
      }
      returnValue = current->value;
   }

   return current->value;
}

void LinkedList::addFront(int value) {
   // TODO
}

void LinkedList::addBack(int value) {
   Node* toAdd = new Node(value, nullptr);

   if(head == nullptr) {
      head = toAdd;
   } else {
      Node* current = head;
      while(current->next != nullptr) {
         current = current->next;
      }

      current->next = toAdd;
   }
}

void LinkedList::removeBack() {
   // TODO
}

void LinkedList::removeFront() {
   // TODO
}

void LinkedList::clear() {
   // TODO
}

