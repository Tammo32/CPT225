#include "Card.h"
#include <iostream>

// CONSTRUCTOR
Card::Card() { 
    std::cout << "In Card default constructor" << std::endl;
    colour = new int(0);
    number = new int(0);
};

// DECONSTRUCTOR
Card::~Card() { 
    std::cout << "In Card deconstructor" << std::endl;
    delete colour;
    delete number;
};

// CUSTOM CONSTRUCTOR
Card::Card(int c, int n) { 
    // Card();
    // *colour = c;
    // *number = n;

    std::cout << "In Card custom constructor" << std::endl;
    colour = new int(c);
    number = new int(n);
};

// COPY CONSTRUCTOR
Card::Card(Card& other) { 
    std::cout << "In Card copy constructor" << std::endl;
    // Shallow copy
    // number = other.number;
    // colour = other.colour;

    // Deep copy
    number = new int(*other.number);
    colour = new int(*other.colour);

    

};

int Card::getNumber() {
    return *number;
};

void Card::setNumber(int n) {
    *number = n;
};