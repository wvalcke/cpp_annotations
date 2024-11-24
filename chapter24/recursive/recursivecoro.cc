#include "main.ih"

namespace
{
    size_t s_value = 0;
}

//def
Recursive recursiveCoro(bool recurse)
{
    while (true)
    {
        for (size_t idx = 0; idx != 2; ++idx)
            co_yield ++s_value;

        // here recursiveCoro will recursively be called

        if (not recurse)
            break;

        Recursive rec = recursiveCoro(false);

        while (true)
        {
            size_t value = rec.next();
            if (rec.done())
                break;

            co_yield value;
        }

        for (size_t idx = 0; idx != 2; ++idx)
            co_yield ++s_value;
    }
}
//=
