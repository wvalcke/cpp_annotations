#include <concepts>
#include <string>

using namespace std;

template <typename LHS, typename RHS>
concept Convertible =
    requires(LHS lhs)
    {
        { lhs } -> std::convertible_to<RHS>;
    };

template <typename RHS, typename LHS>
    requires Convertible<LHS, RHS>
void fun(LHS lhs)
{}

int main()
{                           // note: LHS is the <...>'s type
    fun<double>(12);        // from int to double
    fun<int>(12.5);         // from double to int
    fun<std::string>("a");  // from NTBS to string
    //fun<std::string>(12);   // constraints not satisfied
}
