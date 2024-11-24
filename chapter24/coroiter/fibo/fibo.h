#ifndef INCLUDED_FIBO_
#define INCLUDED_FIBO_

#include "../types/types.h"
#include "../../promisebase/promisebase.h"

class Fibo
{
    class State: public PromiseBase<Fibo, State>
    {
        Triplet d_start;
        Triplet &d_reset;

        Triplet d_value;
        size_t d_id;

        public:
            State(Triplet &start);

            std::suspend_always initial_suspend();
            std::suspend_always yield_value(Triplet const &value);

            Triplet const &value() const;
            void reset();               // to Start
    };
    // State ENDS

    using Handle = std::coroutine_handle<State>;
public:
    Handle d_handle;

    // to access the State, call d_handle.promise()     <<<<<<<<<

    public:
        using promise_type = State;

        explicit Fibo(std::coroutine_handle<State> handle);
        ~Fibo();

        Triplet const &next();
        Triplet const &value() const;
        void reset();

//        void setTriplet(Triplet const &value);
//        size_t id() const;
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
