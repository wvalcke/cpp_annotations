#include <concepts>
#include <string>
#include <iostream>

using namespace std;

template <typename ...Types>
struct allIntegralTypes;
    
template <>
struct allIntegralTypes<>
{
    static bool const value = true;
};

template <typename First, typename ...Types>
struct allIntegralTypes<First, Types ...>
{
    static bool const value = std::is_integral<First>::value and
                                allIntegralTypes<Types ...>::value;
};

template <typename ...Types>
    concept IntegralOnly = allIntegralTypes<Types ...>::value;
    
template <IntegralOnly ...Types>
void fun(Types ...types)
{}

int main(int argc, char*argv[])
{
    fun(1, 90);
    // does not compile as double is not an integral type
    // fun(1, 2.5, 90);
    fun();
}
