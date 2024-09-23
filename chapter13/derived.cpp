#include <iostream>

class A
{
public:
    A() 
    {
        std::cout << "Constructing A" << '\n';
    }
    void method()
    {
        std::cout << "method()" << '\n';
    }

    void method(int value)
    {
        std::cout << "method(int) " << value << '\n';
    }
};

class B : private A
{
public:
    B()
    {
        std::cout << "Constructor B" << '\n';
    }

    // althoug we derive private from A, we make both overloaded methods 'method' available in the public
    // interface of class B
    using A::method;
};

int main(int argc, char* argv[])
{
    B b;
    b.method();
    b.method(9);
}
