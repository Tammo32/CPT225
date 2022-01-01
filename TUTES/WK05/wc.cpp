#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv) {

    // std::cout << "Argc = " << argc;
    
    int chars = 0;
    int lines = 0;
    int words = 0;
    bool in_word = false;

    std::ifstream file;

    if(argc != 1) {
        file.open(argv[2]);

        if(!file.is_open()) {
            std::cout << "Could not open file\n";
            return 1; // return EXIT_FAIL
        }
    }
    else {
        std::cout << "either flag or filename were missing!!";
        return 1;
    }

    // Start reading the chars from the file and count words, lines, characters
    int c;

    while( (c=file.get()) != EOF ) {
        // std::cout << (char)c << std::endl;
        chars++;

        switch (c) {
            case '\n':
                lines++;
                break;
            case ' ':
            case '\t':
                in_word = false; //No longer in a word
                break;
            default:
                if (!in_word) {
                    in_word = true;
                    words++;
                }
                break;
        }
    }

    // std::string flag(argv[1]);
    // flag.compare("-l");

    if (argv[1][1] == 'l') {
        std::cout << lines << " lines" << std::endl;
    }
    else if(argv[1][1] == 'w') {
        std::cout << words << " words" << std::endl;
    }
    else if(argv[1][1] == 'c') {
        std::cout << chars << " characters" << std::endl;
    }
    else {
        std::cout << "Unknown flag";
    }

    return 0;
}