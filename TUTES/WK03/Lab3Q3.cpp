#include <iostream>

typedef int myInt;
typedef char myChar;
typedef std::string myString;
typedef double myDoubleArray[5];
typedef float* myFloatPtr;

typedef double myDoubleArray2;

int main() {
    
    // In the call stack
    // myInt x = 0;
    // myChar ch = 'c';
    // myString s = "Test";
    // myDoubleArray y = {0,0,0,0,0};
    // float f1 = 1.2;
    // myFloatPtr f2 = &f1;

    // std::cout << x << std::endl;
    // std::cout << ch << std::endl;
    // std::cout << s << std::endl;
    // std::cout << y[0] << std::endl; //for loop to print all elements
    // std::cout << *f2 << std::endl;

    // In the heap
    myInt* x2 = new int(0);
    myString* s2 = new std::string("Nothing");
    myDoubleArray2* y2 = new double[5]; //different typedef
    y[0] = 0; // Arrays cannot be initialised in-line when on the heap
    myFloatPtr f2 = new float(1.2); //already a pointer

    std::cout << *x2 << std::endl;
    std::cout << y[0] << std::endl; //for loop to print all elements

    // deleting/deallocating off the heap
    delete x2;
    delete s2;
    delete[] y;
    delete f2;

    return 0;
}