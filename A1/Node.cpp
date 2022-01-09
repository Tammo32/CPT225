#include "Node.h"
#include <iostream>


Node::Node(int row, int col, int dist_traveled):row(row)
{
    // TODO
    this->row = row;
    this->col = col;
    this->dist_traveled = dist_traveled;
    // this->row = new int(row);
    // this->col = new int(col);
    // this->dist_traveled = new int(dist_traveled);
}

Node::~Node(){
    // TODO
    // std::cout << "In Node deconstructor" << std::endl;
    // delete &row;
    // std::cout << "Node row deleted" << std::endl;
    // // delete &col;
    // std::cout << "Node col deleted" << std::endl;
    // delete &dist_traveled;
    // std::cout << "Node dist_traveled deleted" << std::endl;
    
    // std::cout << "Node row = " << row << std::endl;
    // std::cout << "Node col = " << col << std::endl;
    // std::cout << "Node dis = " << dist_traveled << std::endl;

    // FUNCTIONS WHEN IMPLEMENTATION EMPTY? BECAUSE SINGLE OBJECT PERHAPS?
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
    // int manhattan = ( col - goal->getCol() ) + ( row - goal->getRow() );
    
    // CANNOT HAVE NEGATIVES, SO CHECK THE OTHER DIRECTION
    int row_difference = row - goal->getRow();
    if (row_difference < 0) {
        row_difference = goal->getRow() - row;
    }
    int col_difference = col - goal->getCol();
    if (col_difference < 0) {
        col_difference = goal->getCol() - col;
    }
    int manhattan = row_difference + col_difference;
    return dist_traveled + manhattan;
}

// node copy constructor testing as nodelist driving me nuts
Node::Node(Node& other) {
    // row = new int(*other.row);
    // col = new int(*other.col);
    // dist_traveled = new int(*other.dist_traveled);
    // ^cannot get to work, trying more basic below

    this->row = other.row;
    this->col = other.col;
    this->dist_traveled = other.dist_traveled;
}
    
//--------------------------------                             