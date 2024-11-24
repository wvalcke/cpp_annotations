#include "main.ih"

//main
int main()
{
    Recursive rec = recursiveCoro(true);

    while (true)
    {
        cout << rec.next() << "\n"
                "? ";

        string line;
        if (not getline(cin, line) or line == "q")
            break;
    }
}
//=
