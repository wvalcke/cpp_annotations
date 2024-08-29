#include <iostream>
#include <string>

using namespace std;

void state()
{
    cout << "\n"
            "Bad: " << cin.bad() << " "
            "Fail: " << cin.fail() << " "
            "Eof: " << cin.eof() << " "
            "Good: " << cin.good() << '\n';
}

int main()
{
    string line;
    int x;

    cin >> x;
    state();

    cin.clear();
    getline(cin, line);
    state();

    getline(cin, line);
    state();

    if (cin.rdstate() == ios::goodbit)
    {

    }
}
