#include <iostream>
#include "Parser.hpp"

Parser::Parser(const std::vector<Token> &tokens)
    : tokens(tokens), position(0) {}

Token Parser::currentToken()
{
    if (position >= tokens.size())
    {
        return tokens.back();
    }

    return tokens[position];
}

void Parser::advance()
{
    if (position < tokens.size())
    {
        position++;
    }
}

void Parser::parse()
{
    while (currentToken().type != TokenType::END_OF_FILE)
    {
        std::cout << "Parsing token: "
                  << tokenTypeToString(currentToken().type)
                  << std::endl;
        advance();
    }
}
