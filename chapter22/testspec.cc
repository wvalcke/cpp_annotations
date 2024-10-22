#include <iostream>

using namespace std;

template<typename Type>
void fie(Type const& p)
{
    cout << "The template : " << p << '\n';
}

template<>
void fie<int>(int const &a) // <int> achter fie mag ook worden weggelaten
{
    cout << "Specialization with int " << a << '\n';
}

int main(int argc, char*argv[])
{
    fie(45.9);
    fie(9);
}
