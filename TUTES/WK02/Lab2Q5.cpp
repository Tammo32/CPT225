#include <iostream>
#include <string>

#define RED    0
#define ORANGE 1
#define YELLOW 2
#define GREEN  3
#define BLUE   4
#define INDIGO 5
#define VIOLET 6

class Card {
public:
   // TODO: Constructor
   Card(int c, int n);
   // 4 methods to implement
   int getNumber();
   int getColourAsInt();
   std::string getColourAsString();
   std::string getRule();

private:
   // TODO: Fields to store information
    int color;
    int number;
};

int main(void) {
   // TODO: Implement making a card.
   
   //class constructor(input)
   Card myCard(RED, 7);

   return EXIT_SUCCESS;
}

Card::Card(int c, int n) {
    number = n;
    color = c;
}

int Card::getNumber() {
    return number;
}

int Card::getColourAsInt() {
    return color;
}