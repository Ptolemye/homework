#include <iostream>
#include"Prime_and_SuperPrime.h"
int main()
{
    Prime a(100 ,999);
    SuperPrime b(100, 999);
    cout << "素数有：" << endl;
    a.show();
    cout << endl<<"超级素数有：" << endl;
    b.show();
}
