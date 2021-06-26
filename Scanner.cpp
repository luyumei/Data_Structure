//
// Created by RuoHao Li on 6/25/21.
//

#include "string"
#include "iostream"
#include "dict.h"

static int subscript=0;
dict normal;

dict scanner()
{
    char character; //1
    std::string token;  //"12"
    dict reference; //"12"+"number"
    normal.value="reachTheEnd";
    normal.category="reachTheEnd";
    if(subscript>equation.length()-1)
        return normal;

    character=equation.at(subscript);
    subscript++;
    while(character!='\n')
    {
        while(' ' == character)
        {
            character = equation.at(subscript);
            subscript++;
        }
        if(isdigit(character))
        {
            token=token+character;
            character = equation.at(subscript);
            subscript++;
            while(isdigit(character))
            {
                token=token+character;
                character = equation.at(subscript);
                subscript++;
            }
            subscript--;
            std::cout<<"数字！"<<' '<<token<<std::endl;

            reference.value=token;
            reference.category="number";

            return reference;
        }
        else if('+'==character||'-'==character||'*'==character||'/'==character||'('==character||')'==character||'='==character)
        {
            token=token+character;
            std::cout<<"非数字！"<<' '<<token<<std::endl;

            reference.value=token;
            reference.category="nonNumber";

            return reference;
        }
    }
}