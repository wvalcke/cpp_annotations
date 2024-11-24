#include "writer.ih"

Writer::ValueType const &Writer::next()
{
    d_handle.resume();
    return d_handle.promise().value();
}
