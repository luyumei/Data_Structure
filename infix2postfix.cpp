//
// Created by RuoHao Li on 6/26/21.
//
#include "dict.h"
#include "stack"
#include "iostream"
using namespace std;

string postfix;
static stack<string>operators;    //运算符栈
static string seek;   //瞄一眼栈顶元素

extern dict scanner();
extern dict structFromScanner;  //保证初次进入infix2postfix()的时候structFromScanner已经有初值了

//static bool magicCondition = (operators.top() == "(" && (structFromScanner.value == "+" || structFromScanner.value == "-" || structFromScanner.value == "*" || structFromScanner.value == "/"));
//static bool Prioritization; //算符优先级
//static bool magicCondition = operators.top() == "(" || operators.top() == "+" || operators.top() == "-";

void infix2postfix()
{
    if(structFromScanner.value=="=")
    {
        while(!(operators.empty()))
        {
            postfix = postfix + operators.top();
            operators.pop();
        }
        //运算符栈空了！！！
        cout<<postfix<<endl;
    }
    else
    {
        if ("number" == structFromScanner.category)
        {
            postfix = postfix + structFromScanner.value;
            //#?
            structFromScanner = scanner();
            infix2postfix();
        }
        else if ("nonNumber" == structFromScanner.category && "=" != structFromScanner.value)
        {
            if (operators.empty() || "(" == structFromScanner.value/* || magicCondition*/)
            {
                operators.push(structFromScanner.value);
                structFromScanner = scanner();
                infix2postfix();
            }
            else if (")" == structFromScanner.value)
            {
                seek = operators.top(); //看看现在栈顶是不是'('
                while (seek != "(")
                {
                    postfix = postfix + seek;
                    operators.pop();
                    seek = operators.top();
                }
                //栈顶是'('了！！！
                operators.pop();    //"("出栈
                structFromScanner = scanner();
                infix2postfix();
            }
            else if ("+" == structFromScanner.value || "-" == structFromScanner.value)
            {
                while (!operators.empty() && operators.top() != "(")
                {
                    postfix = postfix + operators.top();
                    operators.pop();
                }
                //运算符栈已空 或 栈顶为'('
                operators.push(structFromScanner.value);
                structFromScanner = scanner();
                infix2postfix();
            }
            else if("*" == structFromScanner.value || "/" == structFromScanner.value)
            {
                while (!operators.empty() && !(operators.top() == "(" || operators.top() == "+" || operators.top() == "-"))
                {
                    postfix = postfix + operators.top();
                    operators.pop();
                }
                operators.push(structFromScanner.value);
            }
            /*else
            {
                Prioritization = structFromScanner.priority > operators.top().priority;
                if (Prioritization) {
                    operators.push(structFromScanner.value);    //PUSH operators , (
                    //PUSH operators , +
                    structFromScanner = scanner();
                    infix2postfix();
                } else {
                    while (Prioritization == false)    //当前运算符的优先级 < 栈顶运算符的优先级
                    {
                        postfix = postfix + operators.top();    //POP operators , + ;to postfix
                        //POP operators , ( ;NOT to postfix
                        //POP operators , * ;to postfix
                        operators.pop();
                        structFromScanner = scanner();
                        infix2postfix();
                    }
                }
            }*/
        }
    }
}