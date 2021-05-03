#include <iostream>
#include "Linear List.h"

using namespace std;

int main() {
    int value, position = 0, length;
    cin >> length;
    arrList<int> a(10000); //表a，长10
//-------------------------------------------------------增------------------------------------------------------------//
    for (int i = 0; i < length; i++) {
        cin >> value; //欲插入的元素value
        a.insert(position, value);
        position++;
    }

    // a.print();

    /*int existed_value, new_value, new_position;
    cin >> existed_value;
    cin >> new_value;
    if(a.getPos(existed_value) != -1)
        a.prior_insert(a.getPos(existed_value) + 1,new_value);
    else
        a.append(new_value);

    a.print();*/
//-------------------------------------------------------删------------------------------------------------------------//
    bool temp;
    int Position;
    cin >> Position;

    if(Position > position){
        cout << "error!";
        return 0;
    }
    temp = a.del(Position - 2);   //删除位置p上的元素

    if(temp != false)
        a.print();
/*-------------------------------------------------------查------------------------------------------------------------//
    cin >> n;   //待查找的元素值

    cout << a.getPos(n) << endl;    //返回所查元素第一次出现的位置*/
    return 0;
}
