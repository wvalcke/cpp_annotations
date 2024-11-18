#include <iostream>

using namespace std;

template<int x>
struct IntType
{
    enum { value = x};
};

int main(int argc, char*argv[])
{
    IntType<1> it;
    cout << "IntType<1> objects have value: " << it.value << "\n" <<
                "IntType<2> objects are of a different type "
                        "and have values " << IntType<2>().value << '\n';
    cout << "IntType<100>, no object, defines `value': " <<
                IntType<100>::value << "\n";
}
