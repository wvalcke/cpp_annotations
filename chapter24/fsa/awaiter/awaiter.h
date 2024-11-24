#ifndef INCLUDED_AWAITER_
#define INCLUDED_AWAITER_

//class
struct Awaiter
{
    static bool await_ready();
    static void await_resume();
};

inline bool Awaiter::await_ready()
{
    return false;
}

inline void Awaiter::await_resume()
{}
//=

#endif
