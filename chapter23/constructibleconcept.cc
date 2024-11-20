#include <concepts>
#include <string>

using namespace std;

template <typename LHS, typename ...Args>
concept Constructible = std::constructible_from<LHS, Args...>;

template <typename T1, typename ...Args>
    requires Constructible<T1, Args...>
T1 fun(Args &&...t2)
{
    return T1( std::forward<Args>(t2)... );
}

int main()
{
    std::string s{ fun<std::string>(5, 'a') };
    std::string s2{ fun<std::string>() };   // slightly weird...
}
