#include "main.ih"

Fibo fiboCoro(Triplet triplet)   // size_t first, size_t next)
{
    while (true)
    {
        get<0>(triplet) = get<1>(triplet);  // size_t ret = pair.first;

        get<1>(triplet) = get<2>(triplet);  // pair.first = pair.second;
        get<2>(triplet) += get<0>(triplet); // pair.second += ret;

        co_yield triplet;
    }
}
