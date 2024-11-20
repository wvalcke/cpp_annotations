#include <iostream>
#include <vector>
#include <string>
#include <concepts>

using namespace std;

template<typename Type>
concept Addable = requires(Type param1, Type param2)
{
    param1 + param2;
};

template <typename Tp>
struct Handler
{
    Handler()
    {
        std::cout << "Generic Handler\n";
    }
};

template <Addable Tp>       // constrain Tp to addable types
struct Handler<Tp>
{
    Handler()
    {
        std::cout << "Handler for types supporting operator+\n";
    }
};    

int main()
{
    Handler<std::vector<int>>{};    // generic
    Handler<int>{};                 // specialized
}
