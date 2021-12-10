#include <iostream>

int main(void) {
    int rows = 6;

    for (int i = rows; i > 0; i--) {
        for (int j = 0; j <= rows; j++) {
            if(j < i) {
                std::cout << " ";
            }
            else {
                std::cout << '*';
            }
        }
        std::cout << std::endl;
    }
    
    return EXIT_SUCCESS;
}