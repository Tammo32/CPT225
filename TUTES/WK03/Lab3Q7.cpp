#include <iostream>

#define ROWS    4
#define COLS    5

void readMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);
bool getCharacter(char* c);

int main (void) {
    char maze[ROWS][COLS] = {};

    readMaze(maze);
    std::cout << maze[0][0] << std::endl;

    printMaze(maze);

    return 0;
}

void readMaze(char maze[ROWS][COLS]) {
    // TODO
    // maze[0][0] = '?';
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            getCharacter(&maze[i][j]);
        }
    }
}

bool getCharacter(char* c) {
    std::cout << "Please enter a char: ";
    std::cin >> *c;

    if (std::cin.eof()) {
        return true;
    }
    else {
        return false;
    }
}

void printMaze(char maze[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
}