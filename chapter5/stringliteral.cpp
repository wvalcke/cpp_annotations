#include <string>
#include <iostream>

using namespace std::literals::string_literals;

int main(int argc, char*argv[])
{
    auto str = "String literal"s;

    std::cout << str << '\n';

}