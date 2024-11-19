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

int main(int argc, char*argv[])
{
    using list3 = TypeList<int, char, bool>;

//    TypeAt<3, list3>::Type invalid;
    TypeAt<0, list3>::Type intVariable = 13;
    TypeAt<2, list3>::Type boolVariable = true;

    cout << "The size of the first type is " <<
                sizeof(TypeAt<0, list3>::Type) << ", "
            "the size of the third type is " <<
                sizeof(TypeAt<2, list3>::Type) << "\n";

    if (typeid(TypeAt<1, list3>::Type) == typeid(char))
        cout << "The typelist's 2nd type is char\n";

    if (typeid(TypeAt<2, list3>::Type) != typeid(char))
        cout << "The typelist's 3nd type is not char\n";
}
