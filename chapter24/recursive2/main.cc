#include "main.ih"

//main
Fibo g_fibo = fiboCoro();

int main()
{
    Recursive rec = recursiveCoro(0);

    size_t value;
    while (rec.next(&value))
    {
        cout << value << "\n"
                "? ";

        string line;
        if (not getline(cin, line) or line == "q")
            break;
    }
}
//=
