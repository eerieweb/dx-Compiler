#include "CodeGen.h"

std::string CodeGen::generate(Expr* expr) {
    result.clear();
    expr->accept(*this);
    return result;
}

void CodeGen::visitLiteralExpr(LiteralExpr& expr) {
    result = expr.value.value;
}

void CodeGen::visitBinaryExpr(BinaryExpr& expr) {
    expr.left->accept(*this);
    std::string left = result;
    expr.right->accept(*this);
    std::string right = result;
    result = left + " " + expr.op.value + " " + right;
}
