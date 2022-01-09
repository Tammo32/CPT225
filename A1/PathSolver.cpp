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
}

NodeList* PathSolver::getNodesExplored(){
    //TODO
    // nodes[NODE_LIST_ARRAY_MAX_SIZE] = new Node*(*other.nodes);
    // length = new int(*other.length);
    nodesExplored = new NodeList();
    return nodesExplored;
}

NodeList* PathSolver::getPath(Env env){
    // TODO
    return NULL;
}

//-----------------------------