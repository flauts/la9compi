#ifndef EXP_H
#define EXP_H

#include <string>
#include <unordered_map>
#include <list>
#include "visitor.h"
using namespace std;
enum BinaryOp { PLUS_OP, MINUS_OP, MUL_OP, DIV_OP,LT_OP, LE_OP, EQ_OP, AND_OP,OR_OP };
enum UnaryOp {NOT_OP};
class Exp {
public:
    virtual int  accept(Visitor* visitor) = 0;
    virtual ~Exp() = 0;
    static string binopToChar(BinaryOp op);
    static  string unopToChar(UnaryOp op);
};

class BinaryExp : public Exp {
public:
    Exp *left, *right;
    BinaryOp op;
    BinaryExp(Exp* l, Exp* r, BinaryOp op);
    int accept(Visitor* visitor);
    ~BinaryExp();
};


class IfExp: public Exp {
public:
    Exp *left;
    Exp *right;
    Exp *center;
    int accept(Visitor *visitor);
    IfExp(Exp* l, Exp* r, Exp* c);
    ~IfExp();
};

class UnaryExp: public Exp {
public:
    Exp* right;
    UnaryOp op;
    UnaryExp(Exp* r, UnaryOp op);
    int accept(Visitor *visitor);
    ~UnaryExp();
};

class NumberExp : public Exp {
public:
    int value;
    NumberExp(int v);
    int accept(Visitor* visitor);
    ~NumberExp();
};

class IdentifierExp : public Exp {
public:
    std::string name;
    IdentifierExp(const std::string& n);
    int accept(Visitor* visitor);
    ~IdentifierExp();
};

class Stm {
public:
    virtual int accept(Visitor* visitor) = 0;
    virtual ~Stm() = 0;
};

class AssignStatement : public Stm {
public:
    std::string id;
    Exp* rhs;
    AssignStatement(std::string id, Exp* e);
    int accept(Visitor* visitor);
    ~AssignStatement();
};

class PrintStatement : public Stm {
public:
    Exp* e;
    PrintStatement(Exp* e);
    int accept(Visitor* visitor);
    ~PrintStatement();
};


class IfStatement : public Stm {
public:
    Exp* condition;
    list<Stm*> then;
    list<Stm*> els;
    IfStatement(Exp* condition, list<Stm*> then, list<Stm*> els);
    int accept(Visitor* visitor);
    ~IfStatement();
};

class WhileStatement : public Stm {
    public:
    Exp* condition;
    list<Stm*> then;
    WhileStatement(Exp* condition, list<Stm*> then);
    int accept(Visitor* visitor);
    ~WhileStatement();
};


class Program {
public:
    std::list<Stm*> slist;
    Program();
    void add(Stm* s);
    ~Program();
};

#endif // EXP_H