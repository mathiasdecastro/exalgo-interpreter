#pragma once

#include <vector>
#include "../lexer/Token.hpp"

class Parser
{
public:
    Parser(const std::vector<Token>& tokens);

    void parse();

private:
    std::vector<Token> tokens;
    size_t position;

    Token currentToken();

    void advance();
};