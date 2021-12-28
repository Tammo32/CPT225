#include <iostream>
#include "Hand.h"

//  Card* cards[MAX_CARDS];
//  int numStored;

Hand::Hand() {
    std::cout << "Hand default constructor" << std::endl;
    for(int i = 0; i < MAX_CARDS ; i++) {
        std::cout << "Memory allocated to Card #" << i+1 << std::endl;
        cards[i] = new Card();
    }

    numStored = 0;
};

Hand::~Hand() {
    std::cout << "Hand class deconstructor" << std::endl;
    // delete[] cards;  
        // OR
    for(int i = 0; i < MAX_CARDS ; i++) {
        delete cards[i];
    }
    delete *cards;
};

void Hand::addCard(Card* card){
    *cards[numStored] = *card;
    numStored++;

    if (numStored > MAX_CARDS) {
        std::cout << "Hand is full";
    }
};

int Hand::getNumCards() {
    return numStored;
};

Card* Hand::getCard(int index) {
    return NULL;
};