#include "Lexer.hpp"
#include <cctype>

Lexer::Lexer(const std::string& source)
    : source(source), position(0)
{
    currentChar = source.empty() ? '\0' : source[0];
}

void Lexer::advance()
{
    position++;

    if (position >= source.size())
    {
        currentChar = '\0';
    }
    else
    {
        currentChar = source[position];
    }
}

void Lexer::skipWhitespace()
{
    while (currentChar != '\0' && std::isspace(currentChar))
    {
        advance();
    }
}

Token Lexer::readNumber()
{
    std::string result;

    while (currentChar != '\0' && std::isdigit(currentChar))
    {
        result += currentChar;
        advance();
    }

    return Token(TokenType::NUMBER, result);
}

Token Lexer::readIdentifier()
{
    std::string result;

    while (currentChar != '\0' && std::isalnum(currentChar))
    {
        result += currentChar;
        advance();
    }

    if (result == "ENTIER") return Token(TokenType::ENTIER, result);
    if (result == "REEL") return Token(TokenType::REEL, result);
    if (result == "CHAINE") return Token(TokenType::CHAINE, result);
    if (result == "BOOLEEN") return Token(TokenType::BOOLEEN, result);

    if (result == "SI") return Token(TokenType::SI, result);
    if (result == "ALORS") return Token(TokenType::ALORS, result);
    if (result == "SINON") return Token(TokenType::SINON, result);
    if (result == "FIN") return Token(TokenType::FIN, result);

    if (result == "POUR") return Token(TokenType::POUR, result);
    if (result == "DE") return Token(TokenType::DE, result);
    if (result == "A") return Token(TokenType::A, result);
    if (result == "FAIRE") return Token(TokenType::FAIRE, result);

    if (result == "FONCTION") return Token(TokenType::FONCTION, result);
    if (result == "RETOURNER") return Token(TokenType::RETOURNER, result);
    if (result == "AFFICHER") return Token(TokenType::AFFICHER, result);

    if (result == "VRAI") return Token(TokenType::VRAI, result);
    if (result == "FAUX") return Token(TokenType::FAUX, result);

    return Token(TokenType::IDENTIFIER, result);
}

std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> tokens;

    while (currentChar != '\0')
    {
        if (std::isspace(currentChar))
        {
            skipWhitespace();
            continue;
        }

        if (std::isdigit(currentChar))
        {
            tokens.push_back(readNumber());
            continue;
        }

        if (std::isalpha(currentChar))
        {
            tokens.push_back(readIdentifier());
            continue;
        }

        if (currentChar == '+')
        {
            tokens.emplace_back(TokenType::PLUS, "+");
            advance();
            continue;
        }

        if (currentChar == '-')
        {
            tokens.emplace_back(TokenType::MINUS, "-");
            advance();
            continue;
        }

        if (currentChar == '<')
        {
            advance();

            if (currentChar == '-')
            {
                advance();
                tokens.emplace_back(TokenType::ASSIGN, "<-");
                continue;
            }
            else
            {
                tokens.emplace_back(TokenType::LESS, "<");
                continue;
            }
        }

        advance();
    }

    tokens.emplace_back(TokenType::END_OF_FILE, "");

    return tokens;
}