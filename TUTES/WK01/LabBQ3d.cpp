#include <iostream>

int main(void) {
    int rows = 6;

    // for (int i = 1; i <= rows; i++) {
    //     // to display spaces
    //     for (int s = i; s < rows; s++) {
    //         std::cout << " ";
    //     }
    //     // to display star == row number
    //     for (int j = 1; j <= (2 * i - 1); j++) {
    //         std::cout << "*";
    //     }
    //     // end line each row
    //     std::cout << std::endl;
    // }  
    // for (int i = 1; i <= rows; i++) {
    //     // to display spaces
    //     for (int s = rows; s < i; s++) {
    //         std::cout << " ";
    //     }
    //     // to display star == row number
    //     for (int j = (2 * i - 1); j <= 1; j++) {
    //         std::cout << "*";
    //     }
    //     // end line each row
    //     std::cout << std::endl;
    // }

    // ALTERNATE STUDENT OPTION
    int stars = 1;
    for (int i = 1; i <= rows; i++) {
        std::cout << std::string(rows - i, ' ') << std::string(rows, '*') << std::endl;
        stars += 2;
    }
    stars -= 2;
    for (int i = 1; i < rows; i++) {
        stars -= 2;
        std::cout << std::string(i, ' ') << std::string(stars, '*') << std::endl;
    }

    return EXIT_SUCCESS;
}