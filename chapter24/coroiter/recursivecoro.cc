#include "main.ih"

Recursive recursiveCoro(size_t level)
{
    cerr << "       entering level: " << level << '\n';

    while (true)
    {
        for (size_t idx = 0; idx != 2; ++idx)
            co_yield get<0>(g_fibo.next());  // ++count + level * 10;

        if (level < 3)
        {
            for (size_t value: recursiveCoro(level + 1))
                co_yield value;
        }

        for (size_t idx = 0; idx != 2; ++idx)
            co_yield get<0>(g_fibo.next());  // ++count + level * 10;

        if (level != 0)
            break;
    }
    cerr << "       leaving level: " << level << '\n';
}
