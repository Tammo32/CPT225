#include <iostream>

// PROTOTYPES
void doubleArray1(int values[], int length);
void doubleArray2(int* values, int length);

int main() {
    
    int x[10] = {1,2,3,4,5,6,7,8,9,10};

    std::cout << "Original data: " << std::endl;
    for(int i = 0; i < 10; i++) {
        std::cout << x[i] << std::endl;
    }

    std::cout << "Data calling the first function: " << std::endl;
    doubleArray1(x, 10);
    for(int i = 0; i < 10; i++) {
        std::cout << x[i] << std::endl;
    }

    std::cout << "Data calling the second function: " << std::endl;
    doubleArray2(x, 10);
    for(int i = 0; i < 10; i++) {
        std::cout << x[i] << std::endl;
    }

    return 0;
}

void doubleArray1(int values[], int length) {
    std::cout << "In function 1" << std::endl;

    for(int i = 0; i < length; i++) {
        values[i] = values[i] * 2;
    }
}

void doubleArray2(int* values, int length) {
    std::cout << "In function 2" << std::endl;

    for(int i = 0; i < length; i++) {
        *values = *values * 2;
        values++;
    }
}