#include "Token.hpp"

std::string tokenTypeToString(TokenType type)
{
    switch (type)
    {
        case TokenType::ENTIER: return "ENTIER";
        case TokenType::REEL: return "REEL";
        case TokenType::CHAINE: return "CHAINE";
        case TokenType::BOOLEEN: return "BOOLEEN";

        case TokenType::SI: return "SI";
        case TokenType::ALORS: return "ALORS";
        case TokenType::SINON: return "SINON";
        case TokenType::FIN: return "FIN";

        case TokenType::POUR: return "POUR";
        case TokenType::DE: return "DE";
        case TokenType::A: return "A";
        case TokenType::FAIRE: return "FAIRE";

        case TokenType::FONCTION: return "FONCTION";
        case TokenType::RETOURNER: return "RETOURNER";
        case TokenType::AFFICHER: return "AFFICHER";

        case TokenType::VRAI: return "VRAI";
        case TokenType::FAUX: return "FAUX";

        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::STRING: return "STRING";

        case TokenType::PLUS: return "PLUS";
        case TokenType::MINUS: return "MINUS";
        case TokenType::STAR: return "STAR";
        case TokenType::SLASH: return "SLASH";
        case TokenType::ASSIGN: return "ASSIGN";

        case TokenType::EQUAL: return "EQUAL";
        case TokenType::NOT_EQUAL: return "NOT_EQUAL";
        case TokenType::GREATER: return "GREATER";
        case TokenType::LESS: return "LESS";
        case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
        case TokenType::LESS_EQUAL: return "LESS_EQUAL";

        case TokenType::LPAREN: return "LPAREN";
        case TokenType::RPAREN: return "RPAREN";
        case TokenType::COMMA: return "COMMA";
        case TokenType::COLON: return "COLON";

        case TokenType::END_OF_FILE: return "EOF";

        default: break;
    }

    return "UNKNOWN";
}