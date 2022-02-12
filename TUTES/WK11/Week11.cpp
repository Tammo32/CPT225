#include <string.h>

#include <iostream>

#define MAX_LENGTH 100

class MyString {
   private:
    char string[MAX_LENGTH];
    int length;

   public:
    MyString(char* s, int l) {
        length = l;
        strcpy(string, s);
    };

    MyString(){};

    // Copy constructor
    MyString(MyString& other) { strcpy(string, other.string); };

    ~MyString(){
        // delete string;
    };

    char& operator[](const int index) { return string[index]; }

    bool operator==(const MyString& other) const {
        int eq = 0;
        for (int i = 0; i < length; i++) {
            if (string[i] == other.string[i]) {
                eq++;
            }
        }
        if (eq == length) {
            return true;
        }
        else {
            return false;
        }
    };

    bool operator<(const MyString& other) const {
        int x;
        x = strcmp(string, other.string);
        if (x < 0) {
            return true;

        }
        else {
            return false;
        }
    };

    bool operator>(const MyString& other) const {
        bool o;
        o = (*this < other);
        return o;
    };

    bool operator!=(const MyString& other) const { return !(*this == other); }
};

int main() {
    char* ptr = (char*)"Test";

    MyString s1(ptr, 4);
    MyString s2(ptr, 4);

    std::cout << (s1 != s2);

    return 0;
}