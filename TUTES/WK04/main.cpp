#include <iostream>
#include "Card.h"
#include "Hand.h"

int main() {
    // Instantiate the card
    Card c1(1,2); // in call stack
    Card c2 = c1; // in call stack - copy constructor => c2.Card(&c1)
    //Card* c3 = new Card();
    
    Card c3(3,4);

    std::cout << "  BEFORE:" << std::endl;
    std::cout << "Card 1 number: " << c1.getNumber() << std::endl;
    std::cout << "Card 2 number: " << c2.getNumber() << std::endl;
    c2.setNumber(0);
    std::cout << "  AFTER:" << std::endl;
    std::cout << "Card 1 number: " << c1.getNumber() << std::endl;
    std::cout << "Card 2 number: " << c2.getNumber() << std::endl;
    //std::cout << "Card 3 number: " << c3->getNumber() << std::endl;


    Hand deck;

    deck.addCard(&c1);
    deck.addCard(&c2);
    deck.addCard(&c3);

    std::cout << deck.getNumCards() << std::endl;

    Hand* deck2 = new Hand();
    deck2->addCard(&c1);
    delete deck2;
    
    return 0;
}