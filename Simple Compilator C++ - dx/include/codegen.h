#ifndef CODEGEN_H
#define CODEGEN_H

#include "AST.h"
#include <string>

class CodeGen : public Visitor {
public:
    std::string generate(Expr* expr);
    void visitLiteralExpr(LiteralExpr& expr) override;
    void visitBinaryExpr(BinaryExpr& expr) override;

private:
    std::string result;
};

#endif // CODEGEN_H
