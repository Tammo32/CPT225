#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){
    // TODO
    std::cout << "Pathsolver default constructor" << std::endl;
    // Node::Node(int row, int col, int dist_traveled)

    // nodesExplored = new Node()->getCol();
    
    // for(int i = 0; i < NODE_LIST_ARRAY_MAX_SIZE; i++) {
    //     nodesExplored[i] = new Node(nodesEx[i]->getRow(), nodesExplored[i]->getCol(), nodesExplored[i]->getDistanceTraveled());
    // }
}

PathSolver::~PathSolver(){
    // TODO
    delete nodesExplored;
}

void PathSolver::forwardSearch(Env env){
    // TODO 
    // Environment will be 20x20
    // Node represented by 3 properties: COL, ROW, DISTANCE TO NODE FROM START
    // Start Node(S) 3,1,0
    // Goal Node(G) 1,3,0
    // P=OPEN LIST -> initially contains (S) pointer
    // C=CLOSED LIST -> initially empty
}

NodeList* PathSolver::getNodesExplored(){
    //TODO
    // nodes[NODE_LIST_ARRAY_MAX_SIZE] = new Node*(*other.nodes);
    // length = new int(*other.length);
    nodesExplored = new NodeList();
    return nodesExplored;
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

//-----------------------------