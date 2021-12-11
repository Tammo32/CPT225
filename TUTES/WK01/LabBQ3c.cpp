#include <iostream>

int main(void) {
    int rows = 6;

    for (int i = 1; i <= rows; i++) {
        // to display spaces
        for (int s = i; s < rows; s++) {
            std::cout << " ";
        }
        // to display star == row number
        for (int j = 1; j <= (2 * i - 1); j++) {
            std::cout << "*";
        }
        // end line each row
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}