#include <iostream>

typedef int myInt;
typedef char myChar;
typedef std::string myString;
typedef double myDoubleArray[5];
typedef float* myFloatPtr;

int main() {
    
    // In the call stack
    myInt x = 0;
    myChar ch = 'c';
    myString s = "Test";
    myDoubleArray y = {0,0,0,0,0};
    float f1 = 1.2;
    myFloatPtr f2 = &f1;

    std::cout << x << std::endl;
    std::cout << ch << std::endl;
    std::cout << s << std::endl;
    std::cout << y[0] << std::endl;
    std::cout << *f2 << std::endl;

    return 0;
}