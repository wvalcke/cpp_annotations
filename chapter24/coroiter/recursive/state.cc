#include "recursive.ih"

//Recursive::State::

Recursive::State::State(size_t level)
:
    d_level(level)
{}

std::suspend_always Recursive::State::initial_suspend()
{
    //cout << "initial_suspend: doesn't suspend\n";
    return {};
}

std::suspend_always Recursive::State::yield_value(size_t value)
{
    d_value = value;
    return {};
}

size_t Recursive::State::level() const
{
    return d_level;
}

size_t Recursive::State::value() const
{
    return d_value;
}
