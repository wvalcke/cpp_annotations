#ifndef INCLUDED_FIBO_
#define INCLUDED_FIBO_

#include <tuple>
#include "../../promisebase/promisebase.h"

struct Fibo
{
   using Triplet = std::tuple<size_t, size_t, size_t>;

    private:
        class State: public PromiseBase<Fibo, State>
        {
            Triplet d_value;

            public:
                std::suspend_always yield_value(Triplet const &value);
                size_t value() const;
        };

        using Handle = std::coroutine_handle<State>;
        Handle d_handle;

    public:
        using promise_type = State;

        explicit Fibo(std::coroutine_handle<State> handle);
        ~Fibo();

        size_t next();
};

inline Fibo::Fibo(std::coroutine_handle<State> handle)
:
    d_handle(handle)
{}

inline Fibo::~Fibo()
{
    if (d_handle)
        d_handle.destroy();
}

extern Fibo g_fibo;

#endif
