#include "recursive.ih"

Recursive::~Recursive()
{
    d_handle.destroy();
}

//next
size_t Recursive::next()
{
    d_handle.resume();
    return d_handle.promise().value();
}
//=

bool Recursive::done() const
{
    return d_handle.done();
}
