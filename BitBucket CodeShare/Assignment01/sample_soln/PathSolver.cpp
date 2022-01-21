#include "PathSolver.h"
#include <iostream>

//Should initialize to nullptr
//Can also create a new NodeList, but make sure this is used later
PathSolver::PathSolver(){
    nodesExplored = nullptr;
}


//Should delete the node list
//Need to check if nullptr if not a new is created in the constructor
PathSolver::~PathSolver(){
    if(nodesExplored != nullptr){
        delete nodesExplored;
        nodesExplored = nullptr;
    }

}

// Make sure that all the new objects are cleaned dup

void PathSolver::forwardSearch(Env env){
    //neighbour node indexes
    int neibourhood_row[4] = {+1, 0, -1, 0};
    int neibourhood_col[4] = {0, -1, 0, +1};

    //Look for the start and end positions
    Node* start_node = nullptr;
    Node* goal_node = nullptr;

    //read start and goal
    readStartGoal(env, &start_node, &goal_node);

    // create an empty list for open list
    NodeList* openList = new NodeList();

    // open list should contain the start node as per the pseudocode
    openList->addElement(start_node);

    // create a closed list This can be a separate list or can be the nodes list
    // need to check if it is previously allocated and clean
    // else memory leak
    if(nodesExplored == nullptr){
        nodesExplored = new NodeList();
    } else{
        delete nodesExplored;
        nodesExplored = new NodeList();
    }

    // Have a pointer to the current node we explore
    Node* curNode = nullptr;
    bool goalReached = false;
    do{
        // select a node to explore ()
        curNode = getNode2Expand(openList, nodesExplored, goal_node);

        //check if the end conditions are satisfied or error
        if (curNode->equals(*goal_node)){
            goalReached = true;
        }else if (curNode == nullptr){
            throw std::runtime_error("Goal cannot be reached!!!");
        }else{
            //End conditions are not satisfied

            //check all neighbours and add to openlist if good
            for (int i = 0; i < 4; i++)
            {
                int exp_row = curNode->getRow() + neibourhood_row[i];
                int exp_col = curNode->getCol() + neibourhood_col[i];
                
                // created on stack
                // need to cleanup if defined on heap with new keyword
                Node tempNode(exp_row, exp_col, 
                                curNode->getDistanceTraveled() + 1);

                if (isInsizeEnv(exp_row, exp_col) 
                            && !isNodeInList(openList, &tempNode))
                {     
                    if (env[exp_row][exp_col] == SYMBOL_GOAL || env[exp_row][exp_col] 
                            == SYMBOL_EMPTY)
                    {
                        openList->addElement(&tempNode);
                    } 
                }
            }

        }
        nodesExplored->addElement(curNode);

    }while(!goalReached);

    

    
    delete start_node;
    delete goal_node;
    delete openList;
    //delete closedList;    only delete if separate closed list created
    
}

// Need to be a deep copy
// ownership is transfered to calling function
NodeList* PathSolver::getNodesExplored(){
    NodeList* retPath = new NodeList(*nodesExplored);

    return retPath;
}

NodeList* PathSolver::getPath(Env env){

    //neighbour node indexes
    int neibourhood_row[4] = {+1, 0, -1, 0};
    int neibourhood_col[4] = {0, -1, 0, +1};

    //Look for the start and end positions
    Node* start_node = nullptr;
    Node* goal_node = nullptr;

    // read the start and goal
    readStartGoal(env, &start_node, &goal_node);

    Node* curNode= nullptr;
    bool goal_found = false;

    // find the goal node in nodesExplored list
    for (int i = 0; i < nodesExplored->getLength() && !goal_found; ++i){
        Node* temp = nodesExplored->getNode(i);    
        if (temp->equals(*goal_node)){
            curNode = temp;
            goal_found = true;
        }
    }

    NodeList* tempList = new NodeList();;
    while (!curNode->equals(*start_node)){
        tempList->addElement(curNode);

        //check the neighbours to see if there is a node with dist_traveled
        // that is one less than that of current node
        bool foundNode = false;
        for(int i=0; i < NUM_NEIGHBOURS; ++i){
            if(foundNode == false){
                //get the neighbour
                int exp_row = curNode->getRow() + neibourhood_row[i];
                int exp_col = curNode->getCol() + neibourhood_col[i];

                //check if it is inside the env
                if (isInsizeEnv(exp_row, exp_col)  ){
                    Node checkNode(exp_row, exp_col, 0);
                    
                    int j = 0;
                    //check if the neighbout is in the nodesExplored list
                    while (j < nodesExplored->getLength()) {
                        if(foundNode == false){
                            Node* tempNode = nodesExplored->getNode(j);    
                            if (tempNode->equals(checkNode) && 
                                tempNode->getDistanceTraveled() == 
                                    curNode->getDistanceTraveled() - 1 ){
                                foundNode = true;
                                curNode = tempNode;
                            }
                        }
                        ++j;
                    }

                }
            }
        }

    }
    // the start node is not added, therefore add it last
    // can change the code to do this within the loop
    tempList->addElement(start_node);

    // the temp list is in reverse order. goal to start
    // Need to flip the list order
    NodeList* path = new NodeList();
    for (int i = tempList->getLength()-1; i >= 0; i--){
        path->addElement(tempList->getNode(i));
    }

    // now you can return a deep copy of the path
    // ownership is transfered to the calling function
    NodeList* retPath = new NodeList(*path);

    //clean up 
    delete path;
    delete tempList;
    delete start_node;
    delete goal_node;

    return retPath;
}


//--------------------------------   

//only works for upto milestone 3
void PathSolver::readStartGoal( Env env, 
                                Node** ptr_start_node, 
                                Node** ptr_goal_node){
    for (int row = 0; row < ENV_DIM; row++){
        for (int col = 0; col < ENV_DIM; col++){
            if (env[row][col] == SYMBOL_START){
                *ptr_start_node = new Node(row, col, 0 );
            }else if (env[row][col] == SYMBOL_GOAL)
            {
                *ptr_goal_node = new Node(row, col, 0);
            } 
        }    
    }

    // it is good to check if start and end exists in the env
    if(*ptr_start_node == nullptr) {
      throw std::runtime_error("Invalid Env - no start point");
    } else if (*ptr_goal_node == nullptr) {
      throw std::runtime_error("Invalid Env - no end point");
    }

}



// return the node to exand in line x of the pseudocode
Node* PathSolver::getNode2Expand(   NodeList* openList, 
                                    NodeList* closedList, Node* goal){
    int openLength = openList->getLength();

    int min_dist = ENV_DIM + ENV_DIM + 1;
    Node* retNode = nullptr;

    for (int i = 0; i < openLength; i++)
    {
        Node* curNode = openList->getNode(i);    
        if (min_dist > curNode->getEstimatedDist2Goal(goal) 
            && !isNodeInList(closedList, curNode)){
                retNode = curNode;
                min_dist = curNode->getEstimatedDist2Goal(goal);
        }
        
    }
    
    return retNode;
}

//function to check if the row and column is inside the env
bool PathSolver::isInsizeEnv(int row, int col){
    
    return (row >= 0) && (row < ENV_DIM) && (col >= 0) && (col < ENV_DIM);
}

//function to check if a given node is in a given list
bool PathSolver::isNodeInList(NodeList* nlist, Node* testNode) {
    // What do you think of the efficiency of this code? can you improve it?
    int length = nlist->getLength();
    bool ret = false;

    for (int i = 0; i < length; ++i){
        Node* curNode = nlist->getNode(i);    
        if (curNode->equals(*testNode))
        {
            ret = true;
        }
    }
    
    return ret;
}