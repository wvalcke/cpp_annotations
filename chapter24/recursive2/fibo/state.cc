#include "fibo.ih"

std::suspend_always Fibo::State::yield_value(Triplet const &value)
{
    d_value = value;
    return {};
}

size_t Fibo::State::value() const
{
    return get<0>(d_value);
}
