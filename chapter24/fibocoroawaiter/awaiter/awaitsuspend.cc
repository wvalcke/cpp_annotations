#include "awaiter.ih"

//        Fibo::Handle await_suspend(Fibo::Handle handle)

//+awaiter
bool Awaiter::await_suspend(Fibo::Handle handle) const
{
//+awaiter
    cerr << "Awaiter called\n";
//+awaiter
    handle.promise().setCycle(d_cycle);
    return false;
}
//+awaiter
