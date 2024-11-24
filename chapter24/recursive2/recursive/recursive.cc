#include "recursive.ih"

Recursive::~Recursive()
{
    d_handle.destroy();
}

//next
bool Recursive::next(size_t *value)
{
    d_handle.resume();

    if (d_handle.done())
        return false;

    *value = d_handle.promise().value();
    return true;
}
//=
