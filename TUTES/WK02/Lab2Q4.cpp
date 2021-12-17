#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// PROTOTYPES
bool getCharacter(char* c);
void getCharacters(char* c, int size);

int main(void) {
    // // (a)
    // char character;
    // cout << "Gimme a character: ";
    // cin >> character;
    // cout << "The character you gave was " << character << endl;

    // // (b)
    // getCharacter(&character);
    // cout << "The character by getCharacter() was " << character << endl;

    // (c)
    int size = 5;
    char characters[size];
    getCharacters(characters, size);
    int i;
    for (i = 0; i < size; i++){
        cout << characters[i] << endl;
    }
    // terminating the character string
    characters[size] = '\0';
    
    //testing for i
    cout << "Output of i is " << i << endl;
    
    cout << "Output of getCharacters() was " << characters << endl;

   return EXIT_SUCCESS;
}

bool getCharacter(char* c) {
    cout << "Gimme a character: ";
    cin >> *c;

    if (cin.eof()) {
        return true;
    }
    else {
        return false;
    }
}

void getCharacters(char* c, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Please enter char: "; 
        cin >> *c;
        c++;
        //OR
        // cin >> c[i];
    }
}