#include <iostream>
#include "Card.h"

int main(void) {
    // FROM PRIOR WEEK
    //class constructor(input)
    //    Card c(RED, 7);
    //    std::cout << c.getColourAsString() << " " << c.getNumber() << std::endl;
    //    std::cout << c.getRule();

    // TODO: Implement making a card.
    Card* c = new Card(0,7);

    std::cout << (*c).getColourAsString() << " " << c->getNumber() << std::endl;

    Card* cards = new Card[5];

    Card temp1(0,7);
    cards[0] = temp1;

    Card temp2(1,2);
    cards[1] = temp2;

    delete c;
    delete[] cards;



    return 0;
}
