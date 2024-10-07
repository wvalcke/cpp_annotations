#include <utility>
#include <iostream>
#include <tuple>

using namespace std;

//binding
pair<int, int> factory()
{
    return { 1, 2 };
}

void fun()
{
    auto [one, two] = factory();

    cout << one << ' ' << two << '\n';
}
//=


//retrieve
void retrieve(int &one)
{
    int two;

    pair<int&, int&> p{one, two};
    p = factory();
    cout << one << ' ' << two << '\n';

    tie(one, two) = factory();

    cout << one << ' ' << two << '\n';
}
//=

//spaceship
struct Data
{
    int d_int;
    string d_string;
    double d_double;
};


bool operator==(Data const &lhs, Data const &rhs)
{
    return tie(lhs.d_int, lhs.d_string, lhs.d_double) ==
           tie(rhs.d_int, rhs.d_string, rhs.d_double);
}

partial_ordering operator<=>(Data const &lhs, Data const &rhs)
{
    return tie(lhs.d_int, lhs.d_string, lhs.d_double) <=>
           tie(rhs.d_int, rhs.d_string, rhs.d_double);
}
//=

int main(int argc, char **argv)
{
    fun();

//stmnts
    int one = 0;
    int two = 0;

    cout << one << ' ' << two << '\n';

    retrieve(one);

    cout << one << ' ' << two << '\n';
//=

}
