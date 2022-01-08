#include "NodeList.h"
#include <iostream>

NodeList::NodeList(){
    // TODO
}

NodeList::~NodeList(){
    // TODO
}

NodeList::NodeList(NodeList& other){
    // TODO - Deep Copy of the NodeList
    //number = new int(*other.number);
    //colour = new int(*other.colour);
    *nodes = new Node(*other.nodes);

}

int NodeList::getLength(){
    // TODO
    return length;
}

void NodeList::addElement(Node* newPos){
    // TODO
}

Node* NodeList::getNode(int i){
    // TODO
}