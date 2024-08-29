#include <string>
#include <iostream>

using namespace std::literals::string_literals;

int main(int argc, char*argv[])
{
    auto str = "String literal"s;

    std::cout << str << '\n';

    std::string str2 = "AZERTY";

    // guarantee shrink to fit

    std::string{str2}.swap(str2);

    std::cout << str2 << '\n';
}
