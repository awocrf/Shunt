#ifndef SHUNT_hpp
#define SHUNT_hpp

#include <ctype.h>
#include <Arduino.h>

#define MAXOPSTACK 384
#define MAXNUMSTACK 384

class Shunt
{
public:
    Shunt();
    virtual ~Shunt();

    double shuntThis(char *in_formula);

private:
    struct operator_type
    {
        char op;
        int prec;
        int assoc;
        int unary;
        double (Shunt::*eval)(double a1, double a2);
    };

    enum
    {
        ASSOC_NONE = 0,
        ASSOC_LEFT,
        ASSOC_RIGHT
    };

    int nopstack;
    int nnumstack;
    double numstack[MAXNUMSTACK];

    operator_type operators[9];
    operator_type *opstack[MAXOPSTACK];

private:
    double eval_add(double a1, double a2);
    double eval_sub(double a1, double a2);
    double eval_uminus(double a1, double a2);
    double eval_exp(double a1, double a2);
    double eval_mul(double a1, double a2);
    double eval_div(double a1, double a2);

    double eval_mod(double a1, double a2);
    struct operator_type *getop(char ch);
    void push_opstack(operator_type *op);
    struct operator_type *pop_opstack();
    void push_numstack(double num);
    double pop_numstack();
    void shunt_op(operator_type *op);
    int isdigit_or_decimal(int c);
};

#endif
