#include <iostream>
#include <memory>

using namespace std;

class Base 
{
public:
    Base()
    {
        cout << "Constructor Base" << '\n';
    }
    ~Base()
    {
        cout << "Destructor Base" << '\n';
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Constructor Derived" << '\n';
    }
    ~Derived()
    {
        cout << "Destructor Derived" << '\n';
    }
};

int main(int argc, char*argv[])
{
    /*
    * Hier is het niet nodig om een deleter te voorzien, dus zonder polymorphism zal hier de
    * destructor van Derived worden opgeroepen (dit is niet zo bij een unique pointer !)
    */
    shared_ptr<Base> bsp(new Derived);
    cout << "----------------" << '\n';

    /*
    * Bij de unique pointer moeten we een deleter voorzien zodat de Derived destructor
    * wordt opgeroepen. 
    */
    unique_ptr<Base> uptr(new Derived);

}

