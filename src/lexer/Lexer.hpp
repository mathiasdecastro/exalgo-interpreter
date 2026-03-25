#pragma once

#include <string>
#include <vector>
#include "Token.hpp"

class Lexer
{
public:
    Lexer(const std::string& input);

    std::vector<Token> tokenize();

private:
    std::string source;
    size_t position;
    char currentChar;

    void advance();
    void skipWhitespace();

    Token readIdentifier();
    Token readNumber();
};