#include <iostream>
#include <utility>

void internal(int x)
{
    std::cout << "Internal called with " << x << '\n';
}

template<typename T>
void wrapper(T&& p)
{
    internal(std::forward<T>(p));
}

void internal2(int&& x)
{
    std::cout << "Internal2 called with " << x << '\n';    
}

template<typename T>
void wrapper2(T&& p)
{
    // does not compile if std::forward is not there
    // because the rvalue reference p has a name, and std:forward makes it 
    // anonymouse again.
    internal2(std::forward<T>(p));
}

int main(int argc, char*argv[])
{
    int x = 8;
    wrapper(x);
    int &y = x;
    wrapper(y);
    int const z = 9;
    wrapper(z);
    int const& zz = x;
    wrapper(zz);

    wrapper2(6);
    // does not compile
    //wrapper2(x);
    //wrapper2(y);
    //wrapper2(zz);
}
