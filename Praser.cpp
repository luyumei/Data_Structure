//
// Created by RuoHao Li on 6/25/21.
//

#include <string>
#include "dict.h"

extern dict scanner();

void Expression();
void Term();
void Expression_prime();
int Factor();
void Term_prime();

static dict structFromScanner;

//总控
int praser()
{
    structFromScanner = scanner();
    Expression();
    if("#" != structFromScanner.value)
        //error
        return (-1);

    return 0;
}
// Expression  -> TE’
void Expression()
{
    Term();
    Expression_prime();
}
// Expression ’ -> +TE’|-TE’|ε
void Expression_prime()
{
    if("+" == structFromScanner.value || "-" == structFromScanner.value)
    {
        structFromScanner = scanner();
        Term();
        Expression_prime();
    }
}
// Term  -> FT’
void Term()
{
    Factor();
    Term_prime();
}
// Term ’ -> *FT’|/FT’|ε
void Term_prime()
{
    if("*" == structFromScanner.value || "/" == structFromScanner.value)
    {
        structFromScanner = scanner();
        Factor();
        Term_prime();
    }
}
// Factor  -> ( Expression )|i
int Factor()
{
    if ("number" == structFromScanner.category)
        structFromScanner = scanner();
    else if("(" == structFromScanner.value)
    {
        structFromScanner = scanner();
        Expression();
        if(")" == structFromScanner.value)
            structFromScanner = scanner();
        else
            return (-1);
    }
    else
        return (-1);

    return 0;
}
