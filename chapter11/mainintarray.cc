#include "intarray.h"
#include <iostream>

using namespace std;

int main(int argc, char*argv[])
{
    IntArray x{ 20 };               // 20 ints

    for (int idx = 0; idx < 20; ++idx)
        x[idx] = 2 * idx;                   // assign the elements

    for (int idx = 0; idx <= 20; ++idx)     // result: boundary overflow
        cout << "At index " << idx << ": value is " << x[idx] << '\n';
}
