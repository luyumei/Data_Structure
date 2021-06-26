//
// Created by RuoHao Li on 6/26/21.
//

#include "string"
#include "stack"
#include "iostream"
#include "dict.h"
using namespace std;

static int subscript=1; //后缀表达式下标
static stack<int>operands;    //运算数栈
static int addend1;
static int addend2;
static int sum;

int computePostfix()
{
    if(isdigit(seekChar))
    {
        string tempStr;
        tempStr=tempStr+seekChar;

        seekChar=postfix.at(subscript);
        subscript++;
        while(seekChar!='#')
        {
            tempStr = tempStr + seekChar;
            seekChar = postfix.at(subscript);
            subscript++;
        }
        int linkedNumber = stoi(tempStr);
        operands.push(linkedNumber);
        seekChar=postfix.at(subscript);
        subscript++;
        computePostfix();
    }
    if('+'==seekChar)
    {
        addend1=operands.top();
        operands.pop();
        addend2=operands.top();
        operands.pop();
        sum=addend2+addend1;
        operands.push(sum);
        if(subscript>postfix.length()-1)
        {
            cout << operands.top() << endl;
            exit(operands.top());
        }
        else
        {
            seekChar = postfix.at(subscript);
            subscript++;
            computePostfix();
        }
    }
    else if('-'==seekChar)
    {
        addend1=operands.top();
        operands.pop();
        addend2=operands.top();
        operands.pop();
        sum=addend2-addend1;
        operands.push(sum);
        if(subscript>postfix.length()-1)
        {
            cout << operands.top() << endl;
            exit(operands.top());
        }
        else
        {
            seekChar = postfix.at(subscript);
            subscript++;
            computePostfix();
        }
    }
    else if('*'==seekChar)
    {
        addend1=operands.top();
        operands.pop();
        addend2=operands.top();
        operands.pop();
        sum=addend2*addend1;
        operands.push(sum);
        if(subscript>postfix.length()-1)
        {
            cout << operands.top() << endl;
            exit(operands.top());
        }
        else
        {
            seekChar = postfix.at(subscript);
            subscript++;
            computePostfix();
        }
    }
    else if('/'==seekChar)
    {
        addend1=operands.top();
        operands.pop();
        addend2=operands.top();
        operands.pop();
        if(addend1!=0)
            sum=addend2/addend1;
        else
            cout<<"除数为0！"<<endl;
        operands.push(sum);
        if(subscript>postfix.length()-1)
        {
            cout << operands.top() << endl;
            exit(operands.top());
        }
        else
        {
            seekChar = postfix.at(subscript);
            subscript++;
            computePostfix();
        }
    }
}