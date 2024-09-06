#include <iostream>
#include <utility>

/*
*
Used as postfix operator, the value's object is returned as an rvalue, temporary const object and 
the post-incremented variable itself disappears from view. Used as prefix operator, the variable is 
incremented, and its value is returned as lvalue and it may be altered again by modifying the prefix 
operator's return value. Whereas these characteristics are not required when the operator is 
overloaded, it is strongly advised to implement these characteristics in any overloaded increment 
or decrement operator.
*/

// this is an exception safe version maintaining the strong guarantee

using namespace std;

class Unsigned
{
    size_t d_value;

    public:
        Unsigned();
        explicit Unsigned(size_t init);
        Unsigned(Unsigned const& other);

        Unsigned &operator++(); // prefix operator
        Unsigned operator++(int); // postfix operator
    private:
        void increment();
        void swap(Unsigned& other);
};

Unsigned::Unsigned()
: d_value(0)
{
    cout << "Unsigned()" << '\n';
}

Unsigned::Unsigned(size_t init)
: d_value(init)
{
    cout << "Unsigned(size_t)" << '\n';
}

Unsigned::Unsigned(Unsigned const& other)
{
    cout << "Unsigned(Unsigned const &)" << '\n';
    d_value = other.d_value;
}

void Unsigned::increment()
{
    d_value++;
}

void Unsigned::swap(Unsigned& other)
{
    std::swap(d_value, other.d_value);
}

Unsigned &Unsigned::operator++()
{
    Unsigned tmp{*this};
    tmp.increment();
    // from here we cannot have exceptions, maintaining the strong guarantee
    swap(tmp);
    return *this;
}

Unsigned Unsigned::operator++(int)
{
    Unsigned tmp{*this};
    tmp.increment();
    // from here we cannot have exceptions, maintaining the strong guarantee
    swap(tmp);
    return tmp;
}

int main(int argc, char*argv[])
{
    Unsigned l_U;
    cout << "Main step 1" << '\n';
    Unsigned l_U2 = l_U++;
    cout << "Main step 2" << '\n';

    Unsigned uns{13};
    uns.operator++(); // prefix increment
    uns.operator++(0); // postfix increment
}
