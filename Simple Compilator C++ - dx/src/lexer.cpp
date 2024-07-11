#include "Lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& source) 
    : source(source), current(0), line(1), column(1) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (!isAtEnd()) {
        char c = advance();
        switch (c) {
            case '+':
                addToken(tokens, TOKEN_PLUS);
                break;
            case '-':
                addToken(tokens, TOKEN_MINUS);
                break;
            case '*':
                addToken(tokens, TOKEN_STAR);
                break;
            case '/':
                addToken(tokens, TOKEN_SLASH);
                break;
            case '(':
                addToken(tokens, TOKEN_LPAREN);
                break;
            case ')':
                addToken(tokens, TOKEN_RPAREN);
                break;
            default:
                if (std::isdigit(c)) {
                    std::string value(1, c);
                    while (!isAtEnd() && std::isdigit(peek())) {
                        value += advance();
                    }
                    addToken(tokens, TOKEN_INT, value);
                } else {
                    addToken(tokens, TOKEN_UNKNOWN);
                }
                break;
        }
    }
    addToken(tokens, TOKEN_EOF);
    return tokens;
}

char Lexer::advance() {
    column++;
    return source[current++];
}

char Lexer::peek() const {
    return source[current];
}

bool Lexer::isAtEnd() const {
    return current >= source.length();
}

void Lexer::addToken(std::vector<Token>& tokens, TokenType type, const std::string& value) {
    tokens.push_back({type, value, line, column});
}
