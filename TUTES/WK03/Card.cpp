#include "Card.h"

Card::~Card() {
    
}

Card::Card() {
    number = 0;
    color = 0;
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

std::string Card::getColourAsString() {
    switch (color) {
        case 0:
            return "Red";
            break;
        case 1:
            return "Orange";
            break;
        case 2:
            return "Yello";
            break;
        case 3:
            return "Green";
            break;
        case 4:
            return "Blue";
            break;
        case 5:
            return "Indigo";
            break;
        case 6:
            return "Violet";
            break;
        default:
            return "Unknown";
            break;
    }
}

std::string Card::getRule() {
    switch (color) {
        case 0:
            return "HIGHEST CARD WINS";
            break;
        case 1:
            return "MOST OF ONE NUMBER WINS";
            break;
        case 2:
            return "MOST OF ONE COLOR WINS";
            break;
        case 3:
            return "MOST EVER CARDS WINS";
            break;
        case 4:
            return "MOST DIFFERENT COLORS WINS";
            break;
        case 5:
            return "MOST CARDS IN A ROW WINS";
            break;
        case 6:
            return "MOST CARDS BELOW 4 WINS";
            break;
        default:
            return "Unknown";
            break;
    }
}