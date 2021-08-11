#include <string>
#include <iostream>
#include <cctype>
#include <stdexcept>

void print_next_token(std::istream& stream);

int main() try {

    while(std::cin) {
        print_next_token(std::cin);
        std::cout << "\n";
    }

}

catch (std::exception& e) {

    std::cerr << "Error: " << e.what() << "\n";
    return -1;

}

catch (...) {

    std::cerr << "An unknown error occured.\n";
    return -1;

}

void lex_name(std::istream& stream);
void lex_number(std::istream& stream);
void lex_operator(std::istream& stream);

bool isoperator(char c) {

    std::string const valid_chars = "+*-/!=<>";
    return valid_chars.find(c) != std::string::npos;

}

void print_next_token(std::istream& stream) {

    char c;

    while (stream.get(c) && std::isspace(c));

    if (!stream) {
        std::cout << "{ end_of_file: \"\" }";
        return;
    }

    if (c == '(') {
        std::cout << "{ open_paren: \"(\" }";
        return;
    }

    if (c == ')') {
        std::cout << "{ close_paren: \")\" }";
        return;
    }

    stream.unget();

    if (std::isalpha(c))
        lex_name(stream);
    else if (std::isdigit(c))
        lex_number(stream);
    else if (isoperator(c))
        lex_operator(stream);
    else
        throw std::runtime_error("Unrecognized character");

}

void lex_name(std::istream& stream) {

    char c;
    std::string name;

    while (stream.get(c) && std::isalpha(c))
        name.push_back(c);
    if (stream)
        stream.unget();

    std::cout << "{ name: \"" << name << "\" }";


}

void lex_number(std::istream& stream) {

    char c;
    std::string number;

    while (stream.get(c) && std::isdigit(c))
        number.push_back(c);
    if (stream)
        stream.unget();
    
    std::cout << "{ number: \"" << number << "\" }";

}

void lex_operator(std::istream& stream) {

    char c;
    std::string op;

    while (stream.get(c) && isoperator(c))
        op.push_back(c);
    if(stream)
        stream.unget();

    std::cout << "{ name: \"" << op << "\" }";

}
