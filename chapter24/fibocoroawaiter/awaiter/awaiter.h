#ifndef INCLUDED_AWAITER_
#define INCLUDED_AWAITER_

#include "../fibo/fibo.h"

//awaiter
class Awaiter
{
    size_t const &d_cycle;

    public:
        Awaiter(size_t const &cycle);

        bool await_suspend(Fibo::Handle handle) const;

        static bool await_ready();
        static void await_resume();
};

inline Awaiter::Awaiter(size_t const &cycle)
:
    d_cycle(cycle)
{}

inline bool Awaiter::await_ready()
{
    return false;
}

inline void Awaiter::await_resume()
{}
//=

#endif
