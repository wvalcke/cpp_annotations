#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {

    }
};

class Derived: public Base
{

};

int main(int argc, char* argv[])
{
    Derived d;
    Base    &br = d;

    cout << typeid(br).name() << '\n';

    cout << typeid(12).name() << '\n';     // prints:  int
    cout << typeid(12.23).name() << '\n';  // prints:  double
}
