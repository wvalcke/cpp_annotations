#include "main.ih"

Fibo g_fibo = fiboCoro({ 0, 0, 1 });

int main()
{
//    Recursive rec = recursiveCoro(0);
//
//    cout << *rec.begin() << '\n';
//    cout << *rec.begin() << '\n';
//    cout << *rec.begin() << '\n';
//    cout << *rec.begin() << '\n';
//    cout << *rec.begin() << '\n';

    for (size_t value: recursiveCoro(0))
    {
        cout << value << "\n"
                "? ";

        string line;
        if (not getline(cin, line) or line == "q")
            break;
    }

}
