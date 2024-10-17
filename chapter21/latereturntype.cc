#include <iostream>
#include <string>

std::string global{"hello world"};

template <typename MEMBER, typename RHS>
auto  add(MEMBER mem, RHS rhs) -> decltype((global.*mem)() + rhs)
{
    return (global.*mem)() + rhs;
}

int main()
{
    std::cout << add(&std::string::length, 3.4) << '\n'; // shows: 14.4
}
