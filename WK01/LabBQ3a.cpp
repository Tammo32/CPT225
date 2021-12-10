#include <iostream>

int main(void) {
    int rows = 6;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
        std::cout << '*';
        }
        std::cout << std::endl;
    }
    
    
    return EXIT_SUCCESS;
}