#include "recursive.ih"

//+beginend
Recursive::Iterator Recursive::begin()
{
//+beginend
    cerr << "Recursive::begin()\n";

//+beginend
    if (d_handle.promise().level() == 0)
        g_fibo.reset();

    d_handle.resume();
    return Iterator{ d_handle.done() ? 0 : d_handle };
}

Recursive::Iterator Recursive::end()
{
    return Iterator{ 0 };
}
//+beginend

bool Recursive::next(size_t *value)
{
    d_handle.resume();

//    cerr << "Rec::next.done(): " << d_handle.done() << '\n';

    if (d_handle.done())
        return false;

    *value = d_handle.promise().value();
    return true;
}

Recursive::~Recursive()
{
//    cerr << "Trying to destroy\n";
    if (d_handle)
    {
//        cerr << "destroying\n";
        d_handle.destroy();
        d_handle = 0;               // SF
    }
}
