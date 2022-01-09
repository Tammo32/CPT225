#include "NodeList.h"
#include <iostream>

NodeList::NodeList(){
    // TODO
    // std::cout << "NodeList default constructor" << std::endl;
    for(int i = 0; i < NODE_LIST_ARRAY_MAX_SIZE; i++) {
        // std::cout << "Memory allocated to Node #" << i+1 << std::endl;
        // nodes[i] = new Node(nodes[i]->getRow(), nodes[i]->getCol(), nodes[i]->getDistanceTraveled());
        nodes[i] = nullptr;
    }
    length = 0;
}

NodeList::~NodeList(){
    // TODO
    // std::cout << "NodeList deconstructor" << std::endl;
    for(int i = 0; i < length; i++) {
        delete nodes[i];
    }
    delete *nodes;
}

NodeList::NodeList(NodeList& other){
    // TODO - Deep Copy of the NodeList

    // SHALLOW COPY?
    // length = other.length;
    // nodes[NODE_LIST_ARRAY_MAX_SIZE] = *other.nodes;
    // nodes[getLength()] = *other.nodes;

    // DEEP COPY
//    nodes[NODE_LIST_ARRAY_MAX_SIZE] = new Node*(*other.nodes);
//    length = new int(*other.length);

}

int NodeList::getLength(){
    // TODO
    return length;
}

void NodeList::addElement(Node* newPos){
    // TODO
    if(length > NODE_LIST_ARRAY_MAX_SIZE) {
        std::cout << "NodeList is full";
    }
    else {
        nodes[length] = new Node(*newPos);
        length++;
    }
}

Node* NodeList::getNode(int i){
    // TODO
    Node* returnedNode = nullptr;

    if( i >= 0 && i < getLength()) {
        returnedNode = nodes[i];
    }

    return returnedNode;
}