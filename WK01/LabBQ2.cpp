#include <iostream>

int main(void) {
    
    // Initialising the variables
    std::string name, dob;
    int age;

    // Requesting user input and storing the data
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "Enter your DOB: ";
    std::cin >> dob;

    // Printing back to the screen
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "DOB: " << dob << std::endl;
    
    return EXIT_SUCCESS;
}