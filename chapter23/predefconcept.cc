#include <iostream>
#include <concepts>

using namespace std;

template <typename LHS, typename RHS>
concept CommonRef = std::common_reference_with<LHS, RHS>;

template <typename T1, typename T2>
    requires CommonRef<T1, T2>
void fun(T1 &&t1, T2 &&t2)
{}

struct B
{};

struct D1: public B
{
};

int main()
{
    fun(4, 'a');
    fun(4.5, 'a');

    D1 d1;
    B b;

    fun(b, d1);     // objects, rvalue refs:
    fun(D1{}, B{}); // all OK
}
