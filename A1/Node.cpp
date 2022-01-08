#include "Node.h"
#include <iostream>


Node::Node(int row, int col, int dist_traveled)
{
    // TODO
    // Node::row = row;
    // Node::col = col;
    // Node::dist_traveled = dist_traveled;

    Node::row = new int(&row);
    Node::col = new int(col);
    Node::dist_traveled = new int(dist_traveled);

    
}

Node::~Node(){
    // TODO
    delete row;
    delete col;
    delete dist_traveled;
}

int Node::getRow(){
    // TODO
    return row;
}

int Node::getCol(){
    // TODO
    return col;
}

int Node::getDistanceTraveled(){
    // TODO
    return dist_traveled;
}

void Node::setDistanceTraveled(int dist_traveled)
{
    // TODO
}

int Node::getEstimatedDist2Goal(Node* goal){
    // TODO
}
    
//--------------------------------                             