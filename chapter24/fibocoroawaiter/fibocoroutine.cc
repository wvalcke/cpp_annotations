#include "main.ih"

//fibo
Fibo fiboCoroutine()
{
    size_t returnFibo = 0;
    size_t next = 1;
    size_t cycle = 0;

    co_await Awaiter{ cycle };
    cerr << "Loop starts\n";

    while (true)
    {
        ++cycle;

        size_t ret = returnFibo;

        returnFibo = next;
        next += ret;

        co_yield ret;
    }
}
//=
