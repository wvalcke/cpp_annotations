#include "floats.ih"

// this is the coroutine writing binary floats

// static
//write
Writer Floats::coWrite()
{
    while (true)
    {
        float value;
        if (not (cin >> value))       // get the next value
            co_return;          // if not: end the coroutine


        Writer::ValueType ret;  // value to return

        ret = Writer::ValueType{ string{
                    reinterpret_cast<char const *>(&value),
                    reinterpret_cast<char const *>(&value + 1) }
                };

        co_yield ret;
    }
}
//=
