//
// Created by RuoHao Li on 6/25/21.
//

#include <string>
#include <iostream>
#include "dict.h"

extern dict scanner();

int Expression();
int Term();
int Expression_prime();
int Factor();
int Term_prime();

static dict structFromScanner;
static int code;

//总控
int praser()
{
    structFromScanner = scanner();
    code=Expression();
    if(0!=code)
        //error
        return (-1);
    else
        return 0;
}

// Expression  -> TE’
int Expression()
{
    code=Term();
    if(code!=0)
        return (-1);
    code=Expression_prime();
    if(code!=0)
        return (-1);
    return 0;
}
// Expression ’ -> +TE’|-TE’|ε
int Expression_prime()
{
    if("+" == structFromScanner.value || "-" == structFromScanner.value)
    {
        structFromScanner = scanner();
        code=Term();
        if(code!=0)
            return (-1);
        code=Expression_prime();
        if(code!=0)
            return (-1);
    }
    return 0;
}
// Term  -> FT’
int Term()
{
    code=Factor();
    if(code!=0)
        return (-1);
    code=Term_prime();
    if(code!=0)
        return (-1);
    return 0;
}
// Term ’ -> *FT’|/FT’|ε
int Term_prime()
{
    if("*" == structFromScanner.value || "/" == structFromScanner.value)
    {
        structFromScanner = scanner();
        code=Factor();
        if(code!=0)
            return (-1);
        code=Term_prime();
        if(code!=0)
            return (-1);
    }
    return 0;
}
// Factor  -> ( Expression )|i
int Factor()
{
    if ("number" == structFromScanner.category)
    {
        structFromScanner = scanner();
        return 0;
    }
    else if("(" == structFromScanner.value)
    {
        structFromScanner = scanner();
        code=Expression();
        if(code!=0)
            return -1;
        if(")" == structFromScanner.value)
        {
            structFromScanner = scanner();
            return 0;
        }
        else
            std::cout<<"右括号不匹配！"<<std::endl;
            return (-1);    //右括号不匹配
    }
    else
        return (-1);
}
