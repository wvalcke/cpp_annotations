#include <iostream>
#include <fstream>
using namespace std;

ofstream out(string const &name)
{
    ofstream ret(name);             // construct ofstream
    return ret;                     // return value optimization, but
}                                   // OK as moving is supported

int main()
{
    ofstream mine(out("out"));      // return value optimizations, but
                                    // OK as moving is supported

    ofstream base("base");
    ofstream other;

    base.swap(other);               // swapping streams is OK

    other = std::move(base);        // moving streams is OK

    // other = base;                // this would fail: copy assignment
                                    // is not available for streams
}