//We can alredy print the tokens present in a stream. Now, instead, we will return them.
//This implementation is suboptimal at best. We can make improvements.
//Sample input: (+ (* 2 2) 3)

#include "lex.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

void print_token(Token const& tok) {

    std::cout << "{ ";

    if (tok.type == open_paren_token)
        std::cout << "open_paren_token";
    else if (tok.type == close_paren_token)
        std::cout << "close_paren_token";
    else if (tok.type == name_token)
        std::cout << "name_token";
    else if (tok.type == number_token)
        std::cout << "number_token";
    else if (tok.type == end_of_file_token)
        std::cout << "end_of_file_token";

    std::cout << ", \"" << tok.value << "\" }\n";

}

int main() try {

    std::vector<Token> tokens;

    while (std::cin)
        tokens.push_back(extract_next_token(std::cin));
    
    std::for_each(tokens.begin(), tokens.end(), print_token);

}

catch (std::exception& e) {

    std::cerr << "Error: " << e.what() << "\n";
    return -1;

}

catch (...) {

    std::cerr << "Unknown error encountered.\n";
    return -1;

}
