//Work in progress past this version.

//We can extract tokens one by one but we couldn't track position information and stuff. In this version, we'll be able to look a few tokens ahead or behind.
//Sample input: (+ (* 2 2) 3)

#include "lexer.hpp"
#include <iostream>


int main() try {

    Lexer lex{std::cin};
    while (lex) {
        auto tok = lex.extract();
        auto pos = lex.get_position();
        std::cout << pos << " " << tok << "\n";
    }

}

catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
    return -1;
}

catch (...) {
    std::cerr << "Unknown error detected.\n";
    return -1;
}
