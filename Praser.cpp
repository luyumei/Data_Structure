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
    if(Expression()==0 || structFromScanner.value=="=")
        return 0;
    else
        return 12;  //开头就不是数字
}

// Expression  -> TE’
int Expression()
{
    if(Term()==0)
    {
        structFromScanner = scanner();
        if(Expression_prime()==0)
            return 0;
        else
            return 10;  //10：Expression_prime出错
    }
    else
        return 11;  //11：Term出错
}
// Expression ’ -> +TE’|-TE’|ε
int Expression_prime()
{
    if("+" == structFromScanner.value || "-" == structFromScanner.value)    //符合第一个或者第二个候选的首符集
    {
        structFromScanner = scanner();
        if(Term()==0)
        {
            structFromScanner = scanner();
            if(Expression_prime()==0)
                return 0;   //一二个候选匹配成功
            else
                return 8;   //8：Expression_prime有错
        }
        else
            return 9;   //9：Term有问题
    }
    else if(")" == structFromScanner.value || "=" == structFromScanner.value)
        return 0;
    else
        return -1;  //神奇的错误！
}
// Term  -> FT’
int Term()
{
    if(Factor()==0)
    {
        structFromScanner = scanner();
        if(Term_prime()==0)
            return 0;
        else
            return 7;   //7:Term_prime有问题
    }
    else
        return 6;   //6: Factor有问题
}
// Term ’ -> *FT’|/FT’|ε
int Term_prime()
{
    if("*" == structFromScanner.value || "/" == structFromScanner.value)
    {
        structFromScanner = scanner();
        if(Factor()==0)
        {
            structFromScanner = scanner();
            if(Term_prime()==0)
                return 0;
            else
                return 4;   //4：Term_prime有问题
        }
        else
            return 5;   //5：Factor有问题
    }
    else if("+" == structFromScanner.value || "-" == structFromScanner.value || ")" == structFromScanner.value || "=" == structFromScanner.value)
        return 0;
    else
        return -1;  //  神奇的错误！
}
// Factor  -> ( Expression )|i
int Factor()
{
    if ("number" == structFromScanner.category)
        return 0;   //advance
    else if("(" == structFromScanner.value)
    {
        structFromScanner = scanner();
        if(Expression()==0)
        {
            if (")" == structFromScanner.value)
                return 0;   //(Expression)得到匹配，factor()执行完毕
            else
                std::cout << "右括号不匹配！" << std::endl;
            return 1;    //1：右括号不匹配
        }
        else
            return 2;   //2：Expression有问题
    }
    else
        return 3;   //3：既不是数字，也不是（
}