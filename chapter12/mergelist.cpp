#include <iostream>
#include <string>
#include <list>
using namespace std;

void showlist(list<string> &target)
{
    for
    (
        list<string>::iterator from = target.begin();
        from != target.end();
        ++from
    )
        cout << *from << " ";

    cout << '\n';
}

int main()
{
    list<string> first;
    list<string> second;

    first.push_back("alpha"s);
    first.push_back("bravo"s);
    first.push_back("golf"s);
    first.push_back("quebec"s);

    second.push_back("oscar"s);
    second.push_back("mike"s);
    second.push_back("november"s);
    second.push_back("zulu"s);

    first.merge(second);
    showlist(first);
}
// shows:
// alpha bravo golf oscar mike november quebec zulu
