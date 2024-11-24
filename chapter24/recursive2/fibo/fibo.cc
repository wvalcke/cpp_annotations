#include "fibo.ih"

size_t Fibo::next()
{
    d_handle.resume();
    return d_handle.promise().value();
}
