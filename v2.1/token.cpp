#include "token.hpp"
#include "lex.hpp"

bool operator==(Token const& lhs, Token const& rhs) {

    return lhs.type == rhs.type && lhs.value == rhs.value;

}

bool operator!=(Token const& lhs, Token const& rhs) {

    return !(lhs == rhs);

}

std::istream& operator>>(std::istream& is, Token& tok) {

    if (is)
        tok = extract_next_token(is);
    return is;

}

std::ostream& operator<<(std::ostream& os, Token const& tok) {

    os << tok.value;
    return os;
    
}
