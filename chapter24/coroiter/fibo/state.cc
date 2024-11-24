#include "fibo.ih"

Fibo::State::State(Triplet &start)
:
    d_start(start),
    d_reset(start)
{
}

void Fibo::State::reset()
{
    d_reset = d_start;
}

std::suspend_always Fibo::State::initial_suspend()
{
    //cout << "Fibo::State::initial_suspend: doesn't suspend\n";

    return {};
}

std::suspend_always Fibo::State::yield_value(Triplet const &value)
{
    d_value = value;
    return {};
}

Triplet const &Fibo::State::value() const
{
    return d_value;
}
