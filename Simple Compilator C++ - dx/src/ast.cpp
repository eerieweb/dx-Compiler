#include "AST.h"

LiteralExpr::LiteralExpr(const Token& value) : value(value) {}

void LiteralExpr::accept(Visitor& visitor) {
    visitor.visitLiteralExpr(*this);
}

BinaryExpr::BinaryExpr(Expr* left, const Token& op, Expr* right) 
    : left(left), op(op), right(right) {}

void BinaryExpr::accept(Visitor& visitor) {
    visitor.visitBinaryExpr(*this);
}
