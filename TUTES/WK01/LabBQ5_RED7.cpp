#include <iostream>
#include <string>

using namespace std;

// PROTOTYPES


int main(void) {
    
    int color;
    cout << "Enter a number in [0,48]";
    cin >> color;

    std::string deck[7] = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"}

    if (color < 0)
    {
        // error
    }
    else if (color <= 6) {
        cout << deck[0] << color + 1;
    }
    else if (color <= 16) {
        cout << "Orange " << color + 1 -7;
    }

    

    return EXIT_SUCCESS;
}

