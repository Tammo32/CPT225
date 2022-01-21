#include "Node.h"
#include <iostream>


Node::Node(int row, int col, int dist_traveled):
                                        row(row), col(col),
                                        dist_traveled(dist_traveled)
{}

Node::~Node(){

}


int Node::getRow(){
    return row;
}

int Node::getCol(){
    return col;
}

int Node::getDistanceTraveled(){
    return dist_traveled;
}

//see if this keyword is uesd
void Node::setDistanceTraveled(int dist_traveled)
{
    this->dist_traveled = dist_traveled;
}

//check for absolute values of the differences
// need to add dist_traveled to row and col diff
int Node::getEstimatedDist2Goal(Node* goal){
    
    int row_dif = 0;
    int col_dif = 0;
  
    row_dif = goal->getRow() - row;
    col_dif = goal->getCol() - col;
    if(row_dif < 0)
        row_dif = -row_dif;
    if(col_dif < 0)
        col_dif = -col_dif;
    
    return row_dif + col_dif + dist_traveled;

}
    
//--------------------------------    

// copy the premitive fields of the class
Node::Node(Node& other):
                    row(other.row), col(other.col),
                    dist_traveled(other.dist_traveled)
{}

// return true of both row and col match the other
bool Node::equals(Node& other){
    return (this->row == other.getRow()) && (this->col == other.getCol());
}