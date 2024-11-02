#include <iostream>

using namespace std;

template<int x>
struct IntType
{
    enum { value = x};
};

int main(int argc, char*argv[])
{
    cout << "IntType<100>, no object, defines `value': " <<
                IntType<100>::value << "\n";
}
