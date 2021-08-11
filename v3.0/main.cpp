//Work in progress

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
    std::cerr << "Unknown error.\n";
    return -1;
}
