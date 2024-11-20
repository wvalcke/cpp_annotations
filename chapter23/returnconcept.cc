#include <iostream>
#include <type_traits>
#include <vector>
#include <string>

using namespace std;

template <typename Type, typename ReturnType> 
concept Return =
requires(Type par)
{
                    // par[..] must return a `ReturnType'
    { par[0] } -> std::same_as<ReturnType&>; 
};

// Does not compile for the moment with g++ 11
template <typename RetType, typename Type> 
    requires Return<Type, RetType>
RetType fun(Type tp)
{
    return tp[0];
}

int main(int argc, char*argv[])
{
    vector<string> l_V = {"1", "2"};
    fun<string>(l_V);
}
