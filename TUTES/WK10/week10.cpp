#include <iostream>

class ComplexNumber {
    private:
        int real;
        int imag;

    public:
        ComplexNumber(int r = 0, int i = 0) {
            real = r;
            imag = i;
        };
    
    void display() {
        std::cout << real << " + " << imag << "i" << std::endl;
    };

    ComplexNumber add(ComplexNumber y) {
        ComplexNumber temp(0,0);
        temp.real = real + y.real;
        temp.imag = imag + y.imag;

        return temp;
    }

    ComplexNumber operator +(ComplexNumber const &obj) {
        ComplexNumber temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;

        return temp;
    }

    ComplexNumber operator !() {
        int temp;
        temp = real;
        real = imag;
        imag = temp;

        ComplexNumber output(real,imag);
        return output;
    }
};

int main() {
    ComplexNumber x(1,2);
    ComplexNumber y(1,1);
    ComplexNumber z(0,0);
    x.display();
    y.display();
    
    z = x.add(y);
    z = x + y;
    z.display();

    !z;
    z.display();

    x = !z;
    x.display();
    
    !z;
    z.display();

    return 0;
}