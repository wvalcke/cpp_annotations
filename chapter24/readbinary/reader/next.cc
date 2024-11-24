#include "reader.ih"

//next
Reader::ValueType const &Reader::next()
{
    d_handle.resume();
    return d_handle.promise().value();
}
//=
