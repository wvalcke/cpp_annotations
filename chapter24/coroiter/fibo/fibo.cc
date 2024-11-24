#include "fibo.ih"

//size_t Fibo::id() const
//{
//    return d_handle.promise().id();
//}

Triplet const &Fibo::value() const
{
    return d_handle.promise().value();
}

Triplet const &Fibo::next()
{
    d_handle.resume();
    return d_handle.promise().value();
}

//void Fibo::setTriplet(Triplet const &value)
//{
//    return d_handle.promise().setTriplet(value);
//}
//

void Fibo::reset()
{
    d_handle.promise().reset();
}
