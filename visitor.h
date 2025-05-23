#ifndef VISITOR_H
#define VISITOR_H
#include "exp.h"
#include <list>

class IfExp;
class UnaryExp;
class BinaryExp;
class NumberExp;
class IdentifierExp;
class AssignStatement;
class PrintStatement;
class WhileStatement;
class IfStatement;
class Program;

class Visitor {
public:
    virtual int visit(UnaryExp* exp) = 0;
    virtual int visit(BinaryExp* exp) = 0;
    virtual int visit(NumberExp* exp) = 0;
    virtual int visit(IdentifierExp* exp) = 0;
    virtual void visit(AssignStatement* stm) = 0;
    virtual void visit(PrintStatement* stm) = 0;
    virtual void visit(WhileStatement* stm) = 0;
    virtual void visit(IfStatement* stm) = 0;
    virtual int visit(IfExp* exp) = 0;
};

class PrintVisitor : public Visitor {
public:
    void imprimir(Program* program);
    int visit(UnaryExp* exp) override;
    int visit(BinaryExp* exp) override;
    int visit(NumberExp* exp) override;
    int visit(IdentifierExp* exp) override;
    void visit(AssignStatement* stm) override;
    void visit(PrintStatement* stm) override;
    void visit(IfStatement* stm) override;
    void visit(WhileStatement* stm) override;
    int visit(IfExp* exp) override;
};

class EVALVisitor : public Visitor {
public:
    void ejecutar(Program* program);
    int visit(UnaryExp* exp) override;
    int visit(BinaryExp* exp) override;
    int visit(NumberExp* exp) override;
    int visit(IdentifierExp* exp) override;
    void visit(AssignStatement* stm) override;
    void visit(PrintStatement* stm) override;
    void visit(IfStatement* stm) override;
    void visit(WhileStatement* stm) override;
    int visit(IfExp* exp) override;
};

#endif // VISITOR_H