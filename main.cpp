//
// Created by RuoHao Li on 6/25/21.
//

#include "string"
#include "iostream"
#include "dict.h"

extern dict scanner();
extern int praser();
extern void infix2postfix();
extern int computePostfix();

std::string equation;

dict structFromScanner;

char seekChar;

int main(){
    std::cin>>equation;

    int test;
    test=praser();

    return test;
}