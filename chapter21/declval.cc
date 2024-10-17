#include <utility>
#include <iostream>

//1
template <typename Type>
decltype(std::declval<Type>().fun()) value()
{
    return 12.5;
}
//=
//2
struct Integral
{
    int fun() const;            // implementation not required
};

struct Real
{
    double fun() const;         // same.
};

int main()
{
    std::cout << value<Integral>() << ' ' << value<Real>() << '\n';
}
//=
