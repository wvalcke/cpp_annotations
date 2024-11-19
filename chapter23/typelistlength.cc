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

int main(int argc, char*argv[])
{
    cout << "The length of the list is " << TypeList<char, int, bool>::size << endl;
}
