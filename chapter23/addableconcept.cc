#include <concepts>
#include <string>
#include <iostream>

template<typename Type>
concept Addable = requires(Type param1, Type param2)
{
    param1 + param2;
};

template <typename Type>
requires Addable<Type>
auto add(Type const& lh, Type const& rh)
{
    return lh+rh;
}

template<typename Type>
auto add2(Type const& lh, Type const& rh) requires Addable<Type>
{
    return lh+rh;
}

template<typename Type>
requires Addable<Type> and std::integral<Type>
auto add3(Type const& lh, Type const& rh)
{
    return lh+rh;
}

template<Addable Type>
auto add4(Type const& lh, Type const& rh)
{
    return lh+rh;
}

auto add5(Addable auto const& lh, Addable auto const& rh)
{
    return lh+rh;
}

int main(int argc, char*argv[])
{
    add(1,2);
    add2(1, 2);
    // does not compile
    //add3(1.0, 3.0);
    add3(1,2);
    add4(1,2);
    add5(1,2);

}

