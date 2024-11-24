#include "main.ih"

Fibo fiboCoro()   // size_t first, size_t next)
{
    Fibo::Triplet triplet{ 0, 0, 1 };

    while (true)
    {
        get<0>(triplet) = get<1>(triplet);  // size_t ret = pair.first;

        get<1>(triplet) = get<2>(triplet);  // pair.first = pair.second;
        get<2>(triplet) += get<0>(triplet); // pair.second += ret;

        co_yield triplet;
    }
}
