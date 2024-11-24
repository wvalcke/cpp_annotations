#include "recursive.ih"

//iter
size_t Recursive::Iterator::operator*() const
{
    return d_handle.promise().value();
}

Recursive::Iterator &Recursive::Iterator::operator++()
{
    d_handle.resume();

    if (d_handle.done())
        d_handle = 0;

    return *this;
}
//=

//cons
Recursive::Iterator::Iterator(Handle handle)
:
    d_handle(handle)
{}
//=
