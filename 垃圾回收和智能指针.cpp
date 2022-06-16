#include <iostream>
#include<crtdbg.h>
#include"stdlib.h"
#include<string>
using namespace std;
template<class T>
class smart_ptr
{
private:
    bool own;
    T* ptr;
    
public:
    smart_ptr(T* _p = 0) :own(_p != 0), ptr(_p){};
    ~smart_ptr()
    {
        if (own)delete ptr;
    }
    T& operator*()
    {
        return *ptr;
    }
};
int main()
{
    int* p = new int(10);
    smart_ptr<int>pa(p);
    cout << *p;
}

