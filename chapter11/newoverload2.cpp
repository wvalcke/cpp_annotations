#include <iostream>
using namespace std;

struct Demo
{
    size_t idx;
    Demo()
    {
        cout << "default cons\n";
    }
    ~Demo()
    {
        cout << "destructor\n";
    }
    void *operator new[](size_t size)
    {
        return ::operator new(size);
    }
    void operator delete[](void *vp)
    {
        cout << "delete[] for: " << vp << '\n';
        ::operator delete[](vp);
    }
};

int main()
{
    Demo *xp;
    cout << ((size_t *)(xp = new Demo[3]))[-1] << '\n';
    cout << xp << '\n';
    cout << "==================\n";
    delete[] xp;
}
// This program displays (your 0x?????? addresses might differ, but
// the difference between the two should be sizeof(size_t)):
//  default cons
//  default cons
//  default cons
//  3
//  0x8bdd00c
//  ==================
//  destructor
//  destructor
//  destructor
//  delete[] for: 0x8bdd008
