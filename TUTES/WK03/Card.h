#include <string>

#ifndef COLORS
#define RED    0
#define ORANGE 1
#define YELLOW 2
#define GREEN  3
#define BLUE   4
#define INDIGO 5
#define VIOLET 6
#endif

class Card {
public:
   // TODO: Constructor
   Card();
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