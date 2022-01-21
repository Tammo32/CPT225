#include "Card.h"

#include <iostream>

Card::Card(Colour _colour, int _number)
{
   this->colour = new Colour(_colour);
   this->number = new int(_number);
}

Card::Card(Card& other) {
   this->colour = new Colour(*other.colour);
   this->number = new int(*other.number);
}

Card::~Card() {
   // std::cout << "Card::~Card" << std::endl;
   std::cout << "Colour = " << colour << std::endl;
   std::cout << "Number = " << number << std::endl;
   delete colour;
   std::cout << "Deleted colour" << std::endl;
   std::cout << "Colour = " << colour << std::endl;
   std::cout << "Number = " << number << std::endl;
   delete number;
   std::cout << "Deleted number" << std::endl;
   std::cout << "Colour = " << colour << std::endl;
   std::cout << "Number = " << number << std::endl;
}

Colour Card::getColour() {
   return *colour;
}

int Card::getNumber() {
   return *number;
}
