#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

// Helper test functions
void testNode();
void testNodeList();
bool getCharacter(char* c);

// Read a environment from standard input.
void readEnvStdin(Env env);

// Print out a Environment to standard output with path.
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList* solution);


int main(int argc, char** argv){
    // THESE ARE SOME EXAMPLE FUNCTIONS TO HELP TEST YOUR CODE
    // AS YOU WORK ON MILESTONE 2. YOU CAN UPDATE THEM YOURSELF
    // AS YOU GO ALONG.
    // COMMENT THESE OUT BEFORE YOU SUBMIT!!!
    // std::cout << "TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT!!!" << std::endl;
    // testNode();
    // testNodeList();
    // std::cout << "DONE TESTING" << std::endl << std::endl;

    // Load Environment 
    Env env;
    readEnvStdin(env);
    
    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    PathSolver* pathSolver = new PathSolver();
    pathSolver->forwardSearch(env);

    NodeList* exploredPositions = nullptr;
    exploredPositions = pathSolver->getNodesExplored();

    // Get the path
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    NodeList* solution = pathSolver->getPath(env);

    printEnvStdout(env, solution);

    delete pathSolver;
    delete exploredPositions;
    delete solution;

}

void readEnvStdin(Env env){
    //TODO 
    int numChars = 0;
    int totalChars = ENV_DIM*ENV_DIM;

    for(int i = 0; i < ENV_DIM; i++) {
        for(int j = 0; j < ENV_DIM; j++) {
            // if(std::cin.good()){
                // importedChars = getCharacter(&env[i][j]);
                std::cin >> env[i][j];
                // Test read by printing
                // std::cout << i << ", " << j << std::endl;
                // std::cout << env[i][j] << std::endl;
                numChars++;
            // }
        }
    }
    // TODO Implement check that maze format correct
    // std::cout << numChar << std::endl;
    // std::cout << totalChars << std::endl;
    if (totalChars != numChars) {
        std::cout << "Error with Maze!" << std::endl;
    }
}

bool getCharacter(char* c) {
    std::cin >> *c;

    if (std::cin.eof()) {
        return true;
    }
    else {
        return false;
    }
}

void printEnvStdout(Env env, NodeList* solution) {
    //TODO - basic replication print out at this stage
    for(int i = 0; i < ENV_DIM; ++i) {
        for(int j = 0; j < ENV_DIM; ++j) {
            std::cout << env[i][j];
        }
        std::cout << std::endl;
    }
}

void testNode() {
    std::cout << "TESTING Node" << std::endl;

    // Make a Node and print out the contents
    Node* node = new Node(1, 1, 2);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;
    std::cout << "Test node deleted and back in testNode" << std::endl;

    // Change Node and print again
    node = new Node(4, 2, 3);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;
}

void testNodeList() {
    std::cout << "TESTING NodeList" << std::endl;

    // Make a simple NodeList, should be empty size
    NodeList* nodeList = new NodeList();
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add a Node to the NodeList, print size
    Node* b1 = new Node(1, 1, 1);
    nodeList->addElement(b1);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add second Nodetest
    Node* b2 = new Node(0, 0, 1);
    nodeList->addElement(b2);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Test Get-ith - should be 0,0,1
    Node* getB = nodeList->getNode(1);
    std::cout << getB->getRow() << ",";
    std::cout << getB->getCol() << ",";
    std::cout << getB->getDistanceTraveled() << std::endl;

    // Print out the NodeList
    std::cout << "PRINTING OUT A NODELIST IS AN EXERCISE FOR YOU TO DO" << std::endl;
    for(int i = 0; i < nodeList->getLength(); i++) {
        std::cout << nodeList->getNode(i)->getRow() << ", ";
        std::cout << nodeList->getNode(i)->getCol() << ", ";
        std::cout << nodeList->getNode(i)->getDistanceTraveled() << std::endl;
    }
}