#ifndef LEX_HPP
#define LEX_HPP

#include "token.hpp"
#include <istream>

Token extract_next_token(std::istream& stream);

#endif
