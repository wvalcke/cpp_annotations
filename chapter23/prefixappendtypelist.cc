#include <iostream>
#include <string>

using namespace std;

template <typename ...Types>
struct TypeList;

template <typename Head, typename ...Tail>
struct TypeList<Head, Tail...>
{
    enum { size = 1 + TypeList<Tail...>::size };
};

template<>
struct TypeList<>
{
    enum { size = 0 };
};

template <typename ...Types>
struct Append;

template <typename ...Types>
struct Prefix;

template <typename NewType, typename ...Types>
struct Append<TypeList<Types...>, NewType>
{
    using List = TypeList<Types..., NewType>;
};

template <typename NewType, typename ...Types>
struct Prefix<NewType, TypeList<Types...>>
{
    using List = TypeList<NewType, Types...>;
};

int main(int argc, char*argv[])
{
    using list3 = TypeList<int, char, bool>;
    using list4 = Append<list3, std::string>::List;
    using list4bis = Prefix<std::string, list3>::List;
}
