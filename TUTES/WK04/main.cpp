#include <iostream>
#include "Card.h"

int main() {
    // Instantiate the card
    Card c1(1,2); // in call stack
    Card c2 = c1; // in call stack - copy constructor
    Card* c3 = new Card();

    std::cout << "Card 1 number: " << c1.getNumber() << std::endl;
    std::cout << "Card 2 number: " << c2.getNumber() << std::endl;
    std::cout << "Card 3 number: " << c3->getNumber() << std::endl;
    
    return 0;
}