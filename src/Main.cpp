#include <iostream>
#include <sstream>
#include <fstream>
#include "lexer/Lexer.hpp"
#include "lexer/Token.hpp"
#include "parser/Parser.hpp"

/*int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: exalgo <file.exa>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];
    std::ifstream file(filePath);

    if (!file)
    {
        std::cerr << "Error: cannot open file " << filePath << std::endl;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string content = buffer.str();

    std::cout << "File content:\n\n";
    std::cout << content << std::endl;

    return 0;
}*/

int main()
{
    std::string const code = "ENTIER x <- 5 + 3";

    Lexer lexer(code);
    auto const tokens = lexer.tokenize();

    std::cout << "\n=== PARSER ===" << std::endl;
    Parser parser(tokens);
    parser.parse();

    return 0;
}