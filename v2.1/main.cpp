//Operator overloading and other improvements
//sample input: (+ (* 2 2) 3)

#include "lex.hpp"
#include<iostream>
#include <vector>
#include <algorithm>

int main() try {

    Token tok;
    
    while (std::cin >> tok)
        std::cout << tok << "\n";

}

catch (std::exception e) {

    std::cerr << "Error: " << e.what() << ".\n";
    return -1;

}

catch (...) {

    std::cerr << "Unknown error detected.\n";
    return -1;

}
