#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){
    // TODO
    // std::cout << "Pathsolver default constructor" << std::endl;
    // Node::Node(int row, int col, int dist_traveled)
    nodesExplored = nullptr;
}

PathSolver::~PathSolver(){
    // TODO
    delete nodesExplored;
}

void PathSolver::forwardSearch(Env env){
    // TODO 
    // Node represented by 3 properties: COL, ROW, DISTANCE TO NODE FROM START
    // Input: E - the environment
    // Input: S - start location of the robot in the environment
    // Input: G - goal location for the robot to get reach
    // Need to find start and goal nodes
    Node* start = nullptr;
    Node* goal = nullptr;
    for (int i = 0; i < ENV_DIM; i++) {
        for (int j = 0; j < ENV_DIM; j++) {
            if (env[i][j] == SYMBOL_START) {
                start = new Node(i,j,0);
            }
            if (env[i][j] == SYMBOL_GOAL) {
                goal = new Node(i,j,0);
            }
        }
    }

    // Let P be a list of positions the robot can reach, with distances 
    //  (initially contains S). This is also called the open-list.
    NodeList* openList = new NodeList();
    openList->addElement(start);
    // Let C be a list of positions the that has already being explored, with 
    //  distances (initially empty). This is also called the closed-list.
    // NodeList* closedList = nullptr;
    //Using nodesExplored list instead
    if(nodesExplored == nullptr){
        nodesExplored = new NodeList();
    } else{
        delete nodesExplored;
        nodesExplored = new NodeList();
    }

    //      REPEAT      <--- do while?
    //          Select the node p from the open-list P that has the smallest estimated
    //              distance (see Section 3.2.2) to goal and, is not in the closed-list C.
    //          FOR Each position q in E that the robot can reach from p DO
    //              Set the distance_travelled of q to be one more that that of p
    //              Add q to open-list P only if it is not already in it.
    //          END
    //          Add p to closed-list C.
    //      UNTIL The robot reaches the goal, that is, p == G, or no such position p can be found

    // Select the node p from the open-list P that has the smallest estimated
    //  distance (see Section 3.2.2) to goal and, is not in the closed-list C.
    Node* pNode = nullptr;
    bool goalReached = false;
    // neighbouring node indexes
    int nRow[4] = {+1, 0, -1, 0};
    int nCol[4] = {0, -1, 0, +1};
    do {
        // Select the node p
        pNode = selectPNode(openList, nodesExplored, goal);
        // Check if goal reached
        if (pNode->equals(*goal)) {
            goalReached = true;
        } else if (pNode == nullptr) {
            throw std::runtime_error("Impossible goal"); 
        } else {
            // Check neighbouring nodes then add to openList
            for (int i = 0; i < 4; i++)
            {
                int potentialRow = pNode->getRow() + nRow[i];
                int potentialCol = pNode->getCol() + nCol[i];
                
                Node tempNode(potentialRow, potentialCol, 
                                pNode->getDistanceTraveled()+1);
                
                // Check within environment and not already in list
                // if ((potentialRow >= 0) && (potentialCol < ENV_DIM)) { 
                //     if ((potentialRow >= 0) && (potentialCol < ENV_DIM)) {
                    if (withinEnvironment(potentialRow, potentialRow)) {
                        if (!alreadyInList(openList, &tempNode)) {
                            if (env[potentialRow][potentialCol] == SYMBOL_GOAL 
                                || env[potentialRow][potentialCol] == SYMBOL_EMPTY) {
                                openList->addElement(&tempNode);
                            }
                        }
                    }
            }
        }
        nodesExplored->addElement(pNode);
    } while (!goalReached);

    std::cout << "Goal reached" << std::endl;

    // Clean up the stack
    delete start;
    delete goal;
    delete openList;
}

Node* PathSolver::selectPNode(NodeList* openList, NodeList* closedList, Node* goal) {
    Node* pNode = nullptr;
    int listLength = openList->getLength();
    int min_dist = ENV_DIM + ENV_DIM + 1;
    
    for (int i = 0; i < listLength; i++)
    {
        Node* current = openList->getNode(i);    
        if (min_dist > current->getEstimatedDist2Goal(goal)) { 
            if (!alreadyInList(closedList, current)){
                pNode = current;
                min_dist = current->getEstimatedDist2Goal(goal);
            }
        }
    }
    return pNode;
}

bool PathSolver::alreadyInList(NodeList* nList, Node* node) {
    bool inList = false;
    int length = nList->getLength();

    for (int i = 0; i < length; ++i){
        Node* current = nList->getNode(i);    
        if (current->getRow() == node->getRow()) {
            if (current->getCol() == node->getCol()) {
                inList = true;
            } else {
                inList = false;
            }
        }
    }
    return inList;
}

NodeList* PathSolver::getNodesExplored(){
    //TODO
    NodeList* exploredNodes = new NodeList(*nodesExplored);
    return exploredNodes;
}

NodeList* PathSolver::getPath(Env env){
    // TODO: GOAL to START (SHORTEST)
    // Closed List(C), now saved in NODES EXPLORED field
    // last element is the goal node
    // start from goal nodes, explore neighbours
    // check if next node exists and if distance 1 less than current
    // REPEAT
    // if node not on list then ignore
    // if not 1 less distance then ignore
    // GOAL L, next L-1, then L-2 etc

    return NULL;
}

bool PathSolver::withinEnvironment(int row, int col){
    return (row >= 0) && (row < ENV_DIM) && (col >= 0) && (col < ENV_DIM);
}

//-----------------------------