#include "main.ih"

//coro
Recursive recursiveCoro(size_t level)
{
    while (true)
    {
        for (size_t idx = 0; idx != 2; ++idx)
            co_yield g_fibo.next();

        if (level < 5)
        {
            Recursive rec = recursiveCoro(level + 1);
            size_t value;
            while (rec.next(&value))
                co_yield value;
        }

        for (size_t idx = 0; idx != 2; ++idx)
            co_yield g_fibo.next();

        if (level > 0)
            break;
    }
}
//=
