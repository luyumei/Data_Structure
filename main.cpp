//
// Created by RuoHao Li on 6/25/21.
//

#include "string"
#include "iostream"
#include "dict.h"

extern dict scanner();
extern int praser();
std::string equation;

int main(){
    std::cin>>equation;
    std::cout<<equation<<std::endl;
    dict test;
    while(1)
    {
        test=scanner();
        if(test.category=="reachTheEnd")
            return 0;
    }
}