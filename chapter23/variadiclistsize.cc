#include <iostream>

using namespace std;

template <typename ...Types>
struct TypeList
{
    TypeList(const TypeList&) = delete;
    enum { size = sizeof...(Types) };
};

int main(int argc, char*argv[])
{
    cout << "The length of the list is " << TypeList<char, int, bool>::size << endl;
}
