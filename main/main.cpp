#include <iostream>
#include"Stack.h"
#include"StackList.h"

int main()
{
    TStackList<int> S;

    S.Push(10);
    S.Push(11);
    S.Push(2);
    S.Push(12);
    std::cout<<S.MinElem()<< "\nHi\n";
    return 0;
}
