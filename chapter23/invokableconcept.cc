#include <concepts>
#include <iostream>
#include <string>

using namespace std;

template <typename Function, typename ...Params>
void fun(Function &&fun, Params &&...params)
    requires std::invocable<Function, Params ...>
{
    fun(std::forward<Params>(params)...);
}

void hello(int value, char const *txt, std::string const &str)
{
    std::cout << value << ' ' << txt << ' ' << str << '\n';
}

int main()
{
    fun(hello, 1, "text", "string");    // promotions are still OK
    // fun(hello, 1);                   // WC: not invocable
}
