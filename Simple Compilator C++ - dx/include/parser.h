#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "AST.h"
#include "Lexer.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    Expr* parse();
private:
    std::vector<Token> tokens;
    size_t current;

    Token advance();
    Token peek() const;
    bool isAtEnd() const;
    Token previous() const;
    bool match(TokenType type);
    Token consume(TokenType type, const std::string& errorMessage);
    
    Expr* expression();
    Expr* term();
    Expr* factor();
};

#endif // PARSER_H
