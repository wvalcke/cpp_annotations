#include "fibo.h"

//cycle
std::suspend_always Fibo::State::yield_value(size_t value)
{
    std::cerr << "Got " << value << " at cycle " << *d_cycle << '\n';
    d_value = value;
    return {};
}
//=
