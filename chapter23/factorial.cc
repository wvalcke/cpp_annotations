#include <iostream>

using namespace std;

template<int n>
struct Factorial
{
    enum {value = n * Factorial<n-1>::value};
};

template<>
struct Factorial<0>
{
    enum {value = 1};
};

int main(int argc, char*argv[])
{
    cout << "The number of permutations of 5 objects is " << Factorial<5>::value << '\n';
};

