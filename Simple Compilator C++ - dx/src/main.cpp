#include <iostream>
#include <fstream>
#include "Lexer.h"
#include "Parser.h"
#include "CodeGen.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <source_file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::string source((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    Expr* expr = parser.parse();

    CodeGen codegen;
    std::string code = codegen.generate(expr);

    std::cout << "Generated Code: " << code << std::endl;

    delete expr;

    return 0;
}
