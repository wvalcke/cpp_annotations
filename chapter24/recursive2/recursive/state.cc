#include "recursive.ih"

std::suspend_always Recursive::State::yield_value(size_t value)
{
    d_value = value;
    return {};
}

size_t Recursive::State::value() const
{
    return d_value;
}
