#include "Node.h"
#include <iostream>


Node::Node(int row, int col, int dist_traveled)
{
    // TODO
    Node::row = row;
    Node::col = col;
    Node::dist_traveled = dist_traveled;

    // Node::row = new int(row);
    // Node::col = new int(col);
    // Node::dist_traveled = new int(dist_traveled);

    
}

Node::~Node(){
    // TODO
    delete &row;
    delete &col;
    delete &dist_traveled;
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
    this->dist_traveled = dist_traveled;

}

int Node::getEstimatedDist2Goal(Node* goal){
    // TODO need to return -> Manhatten distance + distance traveled
    // Estimated distance = distance_travelled of node p + Manhattan distance from p to G
    // Manhattan distance = ( col(p) - col(G) ) + ( row(p) - row(G) )
    int travelled = getDistanceTraveled();
    
    // testing numbers
    int manhattan = ( getCol() - 2 ) + ( getRow() - 2 );


    return travelled + manhattan;
}
    
//--------------------------------                             