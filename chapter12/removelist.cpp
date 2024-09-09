#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    list<string> object;

    object.push_back("Hello"s);
    object.push_back("World"s);
    object.push_back("Hello"s);
    object.push_back("World"s);

    object.remove("Hello"s);

    while (object.size())
    {
        cout << object.front() << '\n';
        object.pop_front();
    }
}
/*
        Generated output:
    World
    World
*/
