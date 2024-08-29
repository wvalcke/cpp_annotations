#include <iostream>
#include <string>
#include <string_view>

using namespace std;

string_view fun()
{
    char hello[] = "hello";
    return { hello };
}

string_view fun2()
{
    static char hello[] = "hello";
    return { hello };
}

int main()
{
    string_view obj = fun();
    cout << obj << '\n';

    string_view obj2 = fun2();
    cout << obj2 << '\n';

}
