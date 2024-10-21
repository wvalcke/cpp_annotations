#include <iostream>
#include <utility>

template<int ...Ints>
struct computer
{
    enum: size_t { s_size = sizeof ...(Ints) };
};

template<int ...Ints>
int forwarder()
{
    return computer<Ints...>::s_size;
}

//specialization, strictly this is here not needed
template<>
int forwarder()
{
    std::cout << "Calling specialization\n";
    return 0;
}

template<typename ...Args>
struct MyStruct
{
    enum: size_t { s_size = sizeof ...(Args)};
};

int main(int argc, char*argv[])
{
    std::cout << "Number of arguments " << forwarder<1, 2, 3>() << '\n';
    std::cout << "Number of arguments " << forwarder<>() << '\n';
    std::cout << "Number of types " << MyStruct<std::tuple<int, int>, double, int, float>::s_size << '\n';
}
