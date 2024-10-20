#include <iostream>

template<typename T = double>
constexpr T pivar = T(3.1415);

template<>
constexpr char const* pivar<char const *> = "The pi var";

template<typename Type>
void fie(Type p)
{
    std::cout << "Value " << p << '\n';
    std::cout << "Template var " << pivar<> << '\n';
    std::cout << "Template var " << pivar<char const*> << '\n';
}

int main(int argc, char*argv[])
{
    fie(6);
}
