#ifndef INCLUDED_FIBO_
#define INCLUDED_FIBO_

#include <iostream>

#include <cstddef>
#include <coroutine>

class Fibo
{
    class State
    {
        size_t const *d_cycle;
        size_t d_value;

        public:
            Fibo get_return_object();

            void setCycle(size_t const &cycle);
            std::suspend_always yield_value(size_t value);

            static std::suspend_always initial_suspend();
            static std::suspend_always final_suspend() noexcept;
            static void unhandled_exception();

            size_t value() const;
    };

    std::coroutine_handle<State> d_handle;

    public:
        using promise_type = State;
        using Handle = decltype(d_handle);

        explicit Fibo(std::coroutine_handle<State> handle);
        ~Fibo();

        size_t next();
};

//cycle
inline void Fibo::State::setCycle(size_t const &cycle)
{
    d_cycle = &cycle;
}
//=

inline std::suspend_always Fibo::State::initial_suspend()
{
    return {};
}

inline std::suspend_always Fibo::State::final_suspend() noexcept
{
    return {};
}

inline void Fibo::State::unhandled_exception()
{}

inline Fibo Fibo::State::get_return_object()
{
    return Fibo{ std::coroutine_handle<State>::from_promise(*this) };
}

inline size_t Fibo::State::value() const
{
    return d_value;
}

//------------------------------------------------------------

inline Fibo::Fibo(std::coroutine_handle<State> handle)
:
    d_handle(handle)
{}

inline Fibo::~Fibo()
{
    if (d_handle)
        d_handle.destroy();
}


#endif
