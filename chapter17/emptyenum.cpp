#include <iostream>

enum EmptyEnum
{};

int main(int argc, char*argv[])
{
    try
    {
        throw EmptyEnum();
    }
    catch (EmptyEnum)
    {
        std::cout << "Caught empty enum\n";
    }
}
