#include <iostream>

using namespace std;

struct A
{
    int a;
};

struct B
{
    int b;
    void bfun() {}
};

struct C: public A, public B
{};

int main()
{
    union BPTR
    {
        void (B::*ptr)();
        unsigned long value[2];
    };
    BPTR bp;
    bp.ptr = &B::bfun;
    cout << hex << bp.value[0] << ' ' << bp.value[1] << dec << '\n';

    union CPTR
    {
        void (C::*ptr)();
        unsigned long value[2];
    };
    CPTR cp;
    cp.ptr = &C::bfun;
    cout << hex << cp.value[0] << ' ' << cp.value[1] << dec << '\n';
}
