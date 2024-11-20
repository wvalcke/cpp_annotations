#include <iostream>
#include <type_traits>
#include <vector>
#include <string>

using namespace std;

template <typename Lhs, typename Rhs>
struct SameTypes            // generic: any two types
{
    static bool const value = false;
};
template <typename Lhs>
struct SameTypes<Lhs, Lhs>  //specialization: equal types
{
    static bool const value = true;
};

template<typename Compound, typename Specified>
concept Same = SameTypes<Compound, Specified>::value;

template <typename Type, typename ReturnType> 
concept Return =
requires(Type par)
{
                    // par[..] must return a `ReturnType'
    { par[0] } -> Same<ReturnType&>; 
};

template <typename RetType, typename Type> 
    requires Return<Type, RetType>
RetType fun(Type tp)
{
    return tp[0];
}

int main(int argc, char*argv[])
{
    vector<string> l_V = {"A", "B"};
    fun<string>(l_V);
}
