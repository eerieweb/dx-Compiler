#ifndef AST_H
#define AST_H

#include <vector>
#include "Lexer.h"

class Visitor;

class Expr {
public:
    virtual ~Expr() = default;
    virtual void accept(Visitor& visitor) = 0;
};

class LiteralExpr : public Expr {
public:
    LiteralExpr(const Token& value);
    void accept(Visitor& visitor) override;
    Token value;
};

class BinaryExpr : public Expr {
public:
    BinaryExpr(Expr* left, const Token& op, Expr* right);
    void accept(Visitor& visitor) override;
    Expr* left;
    Token op;
    Expr* right;
};

class Visitor {
public:
    virtual void visitLiteralExpr(LiteralExpr& expr) = 0;
    virtual void visitBinaryExpr(BinaryExpr& expr) = 0;
};

#endif // AST_H
