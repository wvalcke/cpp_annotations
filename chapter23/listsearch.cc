#include <iostream>

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
struct ListSearch
{
    ListSearch(ListSearch const &) = delete;
};

template <typename SearchType>
struct ListSearch<SearchType, TypeList<>>
{
    ListSearch(ListSearch const &) = delete;
    enum { index = -1 };
};

template <typename SearchType, typename ...Tail>
struct ListSearch<SearchType, TypeList<SearchType, Tail...>>
{
    ListSearch(ListSearch const &) = delete;
    enum { index = 0 };
};

template <typename SearchType, typename Head, typename ...Tail>
struct ListSearch<SearchType, TypeList<Head, Tail...>>
{
    ListSearch(ListSearch const &) = delete;
    enum { tmp = ListSearch<SearchType, TypeList<Tail...>>::index };
    enum { index = tmp == -1 ? -1 : 1+tmp };
};

int main(int argc, char*argv[])
{
    std::cout <<
        ListSearch<char, TypeList<int, char, bool>>::index << "\n" <<
        ListSearch<float, TypeList<int, char, bool>>::index << "\n";
}
