#include <iostream>

using std::cout;
using std::endl;

// PROTOTYPES
void modifyDoublePointer(double* d);
void modifyDoubleReference(double& d);

int main (void) {

    // (a) Declares and initialises an integer
    int integer = 1;
    // (b) Declares and initialises a pointer to the integer
    int* ptr = &integer;
    // (c) Directly modifies the value of the integer
    integer = 10;
    // (d) Uses the pointer to modify the value of the integer
    *ptr = 5;
    // (e) Declares and initialises a double
    double x = 2.5;
    cout << "Before: " << x << endl;
    // (f) Uses a function to modify the value of the double using a pointer to it
    modifyDoublePointer(&x);
    cout << "After pointer mod: " << x << endl;
    // (g) Uses a function to modify the value of the double using a reference to it
    modifyDoubleReference(x);
    cout << "After reference mod: " << x << endl;

   return EXIT_SUCCESS;
}

void modifyDoublePointer(double* d) {
    *d = 10.5;
}

void modifyDoubleReference(double& d) {
    d = 22.1;
}