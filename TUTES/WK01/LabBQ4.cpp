#include <iostream>
#include <string>
#define PI 3.14159265359;

// PROTOTYPES
float AreaCircle(float r);

int main(void) {
    
    float radius, area;

    std::cout << "Enter radius: ";
    std::cin >> radius;
    area = AreaCircle(radius);
    
    // Print out area
    std::cout << "Circle with r=" << radius << " has area=" << area << std::endl;


    return EXIT_SUCCESS;
}

float AreaCircle(float r) {
    return r * r * PI;
}