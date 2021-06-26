//
// Created by RuoHao Li on 6/25/21.
//

#include "string"
#include "iostream"
#include "dict.h"

extern dict scanner();
extern int praser();
extern void infix2postfix();
std::string equation;

dict structFromScanner;

int main(){
    std::cin>>equation;
    std::cout<<equation<<std::endl;

    structFromScanner = scanner();
    infix2postfix();
}