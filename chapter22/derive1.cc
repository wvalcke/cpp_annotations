#include <iostream>

using namespace std;

template<typename T>
class Base
{
    T const& t;
public:
    Base(T const& t)
    : t(t)
    {
    }
};

template<typename T>
class Derived : public Base<T>
{
public:
    Derived(T const& t);
};

template<typename T>
Derived<T>::Derived(T const& t)
: Base<T>(t)
{

}

class Ordinary : public Base<int>
{
public:
    Ordinary(int p)
    : Base(p) // Hier mag (maar moet niet) Base<int>(p) ook staan
    {}
};

int main(int argc, char*argv[])
{
    Derived<int> myc(8);
    Ordinary ordinary{5};
}
