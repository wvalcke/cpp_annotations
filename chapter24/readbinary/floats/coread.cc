#include "floats.ih"

// this is the coroutine reading binary floats

//read
Reader Floats::coRead() const
{
    ifstream in{ d_filename };

    while (true)
    {
        float value;
        in.read(reinterpret_cast<char *>(&value), sizeof(float));

        if (not in)
            co_return;          // if not: end the coroutine

        co_yield value;
    }
}
//=
