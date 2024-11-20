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

template <size_t index, typename Typelist>
struct TypeAt;

template <size_t index>
struct TypeAt<index, TypeList<>>
{
    static_assert(index < 0, "TypeAt index out of bounds");
    using Type = TypeAt;
};

template <typename Head, typename ...Tail>
struct TypeAt<0, TypeList<Head, Tail...>>
{
    using Type = Head;
};

template <size_t index, typename Head, typename ...Tail>
struct TypeAt<index, TypeList<Head, Tail...>>
{
    using Type = typename TypeAt<index - 1, TypeList<Tail...>>::Type;
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

template <typename EraseType, typename TypeList>
struct Erase;

template <typename EraseType>
struct Erase<EraseType, TypeList<>>
{
    using List = TypeList<>;
};

template <typename EraseType, typename ...Tail>
struct Erase<EraseType, TypeList<EraseType, Tail...>>
{
    using List = TypeList<Tail...>;
};

template <typename EraseType, typename Head, typename ...Tail>
struct Erase<EraseType, TypeList<Head, Tail...>>
{
    using List =  typename
        Prefix<Head,
            typename Erase<EraseType, TypeList<Tail...>>::List
        >::List;
};

template <size_t idx, typename TypeList>
struct EraseIdx;

template <size_t idx>
struct EraseIdx<idx, TypeList<>>
{
    using List = TypeList<>;
};

template <typename EraseType, typename ...Tail>
struct EraseIdx<0, TypeList<EraseType, Tail...>>
{
    using List = TypeList<Tail...>;
};

template <size_t idx, typename Head, typename ...Tail>
struct EraseIdx<idx, TypeList<Head, Tail...>>
{
    using List = typename Prefix<
                Head,
                typename EraseIdx<idx - 1, TypeList<Tail...>>::List
            >::List;
};

template <typename EraseType, typename TypeList>
struct EraseAll: public Erase<EraseType, TypeList>
{};

template <typename EraseType, typename ...Tail>
struct EraseAll<EraseType, TypeList<EraseType, Tail...>>
{
    using List = typename EraseAll<EraseType, TypeList<Tail...>>::List;
};

template <typename EraseType, typename Head, typename ...Tail>
struct EraseAll<EraseType, TypeList<Head, Tail...>>
{
    using List = typename Prefix<
        Head,
        typename EraseAll<EraseType, TypeList<Tail...>>::List
    >::List;
};

template <typename TypeList>
struct EraseDup;

template <>
struct EraseDup<TypeList<>>
{
    using List = TypeList<>;
};

template <typename Head, typename ...Tail>
struct EraseDup<TypeList<Head, Tail...>>
{
    using UniqueTail = typename EraseDup<TypeList<Tail...>>::List;
    using NewTail = typename Erase<Head, UniqueTail>::List;

    using List = typename Prefix<Head, NewTail>::List;
};

int main(int argc, char*argv[])
{
    cout <<
            Erase<int, TypeList<char, double, int>>::List::size << '\n' <<
            Erase<char, TypeList<int>>::List::size << '\n' <<
            Erase<int, TypeList<int>>::List::size << '\n' <<
            Erase<int, TypeList<>>::List::size << "\n";

    if
    (
        typeid(TypeAt<2,
                EraseIdx<1,
                   TypeList<int, char, size_t, double, int>>::List
                >::Type
        )
        == typeid(double)
    )
    cout << "the third type is now a double\n";         
    
    cout <<
        "After erasing size_t from "
            "TypeList<char, int, size_t, double, size_t>\n"
            "it contains " <<
                EraseAll<size_t,
                         TypeList<char, int, size_t, double, size_t>
                >::List::size << " types\n";       
    cout <<
        "After erasing duplicates from "
             "TypeList<double, char, int, size_t, int, double, size_t>\n"
        "it contains " <<
        EraseDup<
            TypeList<double, char, int, size_t, int, double, size_t>
        >::List::size << " types\n";                    
}
