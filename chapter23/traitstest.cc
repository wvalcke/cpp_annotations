#include <iostream>

#include <type_traits>

class MyClass {};

int main(int argc, char*argv[])
{
    if (std::is_class<MyClass>::value)
    {
        std::cout << "This is a class\n";
    }
}
