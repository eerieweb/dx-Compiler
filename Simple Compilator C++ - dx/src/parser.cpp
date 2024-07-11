#include "Parser.h"
#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens) 
    : tokens(tokens), current(0) {}

Expr* Parser::parse() {
    return expression();
}

Token Parser::advance() {
    if (!isAtEnd()) current++;
    return previous();
}

Token Parser::peek() const {
    return tokens[current];
}

bool Parser::isAtEnd() const {
    return peek().type == TOKEN_EOF;
}

Token Parser::previous() const {
    return tokens[current - 1];
}

bool Parser::match(TokenType type) {
    if (isAtEnd()) return false;
    if (peek().type != type) return false;
    advance();
    return true;
}

Token Parser::consume(TokenType type, const std::string& errorMessage) {
    if (match(type)) return previous();
    throw std::runtime_error(errorMessage);
}

Expr* Parser::expression() {
    return term();
}

Expr* Parser::term() {
    Expr* expr = factor();

    while (match(TOKEN_PLUS) || match(TOKEN_MINUS)) {
        Token op = previous();
        Expr* right = factor();
        expr = new BinaryExpr(expr, op, right);
    }

    return expr;
}

Expr* Parser::factor() {
    if (match(TOKEN_INT)) {
        return new LiteralExpr(previous());
    }
    if (match(TOKEN_LPAREN)) {
        Expr* expr = expression();
        consume(TOKEN_RPAREN, "Expect ')' after expression.");
        return expr;
    }
    throw std::runtime_error("Unexpected token.");
}
