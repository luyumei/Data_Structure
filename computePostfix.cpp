//
// Created by RuoHao Li on 6/26/21.
//

#include "string"
#include "stack"
#include "iostream"
using namespace std;

string postfix;
static char seek;
static int subscript=0;
static stack<char>operands;    //运算数栈
static int addend1;
static int addend2;
static int sum;

int computePostfix()
{
    seek=postfix.at(subscript);
    if(isdigit(seek))
    {
        operands.push(int(seek));
        seek=postfix.at(subscript);
        computePostfix();
    }
    if('+'==seek)
    {
        addend1=operands.top();
        operands.pop();
        addend2=operands.top();
        operands.pop();
        sum=addend2+addend1;
        operands.push(sum);
    }
    if('-'==seek)
    {
        addend1=operands.top();
        operands.pop();
        addend2=operands.top();
        operands.pop();
        sum=addend2-addend1;
        operands.push(sum);
    }
    if('*'==seek)
    {
        addend1=operands.top();
        operands.pop();
        addend2=operands.top();
        operands.pop();
        sum=addend2*addend1;
        operands.push(sum);
    }
    if('/'==seek)
    {
        addend1=operands.top();
        operands.pop();
        addend2=operands.top();
        operands.pop();
        if(addend2!=0)
            sum=addend2/addend1;
        else
            cout<<"除数为0！"<<endl;
        operands.push(sum);
    }
    return (operands.top());
}