#include "NodeList.h"
#include <iostream>


// Need to assign all the nodes in array to nullptr
NodeList::NodeList(){
    for (int i = 0; i < NODE_LIST_ARRAY_MAX_SIZE ; ++i){
        nodes[i] = nullptr;
    }
    length = 0;
}

// delete nodes upto length
// can also check if nullptr before deleting but not necessary
NodeList::~NodeList(){
    for (int i = 0; i < length; i++){
        delete nodes[i];
        nodes[i] = nullptr;
    }
    
}

// Deep copy, need to make sure that the new keyword is used up to length.
// Need to make sure that the remaining nodeList elements are pointing to 
// nullptr
NodeList::NodeList(NodeList& other){
    for (int i = 0; i < NODE_LIST_ARRAY_MAX_SIZE ; ++i){
        nodes[i] = nullptr;
    }

    length = other.length;
    for (int i = 0; i < length; ++i)
    {
        nodes[i] = new Node(*other.nodes[i]);
    }
    

}

int NodeList::getLength(){
    return length;
}

// Should create a copy with new keyword
// should check the length of array (negative one is important)
// assign the cpyNode to nodelist
void NodeList::addElement(Node* newPos){
    Node* tCpy = new Node(*newPos);

    if(length < NODE_LIST_ARRAY_MAX_SIZE - 1){
        nodes[length] = tCpy;
        ++length;
    }
}


//should check for array limits
//return nullptr if no node is found in list at the index
Node* NodeList::getNode(int i){
    Node* retNode = nullptr;
    if (i >=0 && i < length){
        retNode = nodes[i];
    }
    return retNode;
}