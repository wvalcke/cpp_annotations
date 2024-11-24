#include "start.ih"
//coro
Start coStart()
{
    char ch;
    while (cin.get(ch))
    {
        if (isalpha(ch))
        {
            cout << "at `" << ch << "' from start to letter\n";
            co_await g_letter;
        }
        else if (isdigit(ch))
        {
            cout << "at `" << ch << "' from start to digit\n";
            co_await g_digit;
        }
        else
            cout << "at char #" << static_cast<int>(ch) <<
                    ": remain in start\n";
    }
    co_await g_done;
}
//=
