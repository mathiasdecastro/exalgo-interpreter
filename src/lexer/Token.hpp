#pragma once

#include <string>

enum class TokenType
{
    // types
    ENTIER,
    REEL,
    CHAINE,
    BOOLEEN,

    // keywords
    SI,
    ALORS,
    SINON,
    DEBUT,
    FIN,
    DE,
    A,
    POUR,
    FAIRE,
    FONCTION,
    RETOURNER,
    AFFICHER,

    // identifiers & literals
    IDENTIFIER,
    NUMBER,
    STRING,
    VRAI,
    FAUX,

    // operators
    PLUS,
    MINUS,
    STAR,
    SLASH,
    ASSIGN,
    EQUAL,
    NOT_EQUAL,
    GREATER,
    LESS,
    GREATER_EQUAL,
    LESS_EQUAL,

    // symbols
    LPAREN,
    RPAREN,
    COMMA,
    COLON,

    // end
    END_OF_FILE
};

struct Token
{
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string& value) : type(type), value(value) {}
};

std::string tokenTypeToString(TokenType type);