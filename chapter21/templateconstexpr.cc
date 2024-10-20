#include <iostream>
using namespace std;

void positive()
{
    cout << "Positive\n";
}
void negative()
{
    cout << "Negative\n";
}

template <int value>
void fun()
{
    if constexpr (value > 0)
        positive();
    else if constexpr (value < 0)
        negative();
}

int main()
{
    fun<4>();
}
