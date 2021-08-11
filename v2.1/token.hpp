#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

int const open_paren_token = 0;
int const close_paren_token = 1;
int const name_token = 2;
int const number_token = 3;
int const end_of_file_token = 4;

struct Token {
    int type;
    std::string value;
};

bool operator==(Token const& lhs, Token const& rhs);
bool operator!=(Token const& lhs, Token const& rhs);

std::istream& operator>>(std::istream& is, Token& tok);
std::ostream& operator<<(std::ostream& os, Token const& tok);

#endif
