
#include <iostream>
#include <string>
#include <iostream>

#include <cstddef>
#include <coroutine>

using namespace std;

class Fibo
{
    class State
    {
        size_t d_value;

        public:
            Fibo get_return_object();

            std::suspend_always yield_value(size_t value);

            static std::suspend_always initial_suspend();
            static std::suspend_always final_suspend() noexcept;
            static void unhandled_exception();

            size_t value() const;
    };

    std::coroutine_handle<State> d_handle;

    public:
        using promise_type = State;

        explicit Fibo(std::coroutine_handle<State> handle);
        ~Fibo();

        size_t next();
};

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

inline std::suspend_always Fibo::State::yield_value(size_t value)
{
    d_value = value;
    return {};
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

size_t Fibo::next()
{
    d_handle.resume();
    return d_handle.promise().value();
}


Fibo fiboCoro()
{
    size_t returnFibo = 0;
    size_t next = 1;

    while (true)
    {
        size_t ret = returnFibo;

        returnFibo = next;
        next += ret;

        co_yield ret;
    }
}

int main(int argc, char **argv)
{
    Fibo fibo = fiboCoro();

    size_t sum = 0;

    for (                       // the sequence of fibonacci numbers
        size_t begin = 0, end = argc == 1 ? 10 : stoul(argv[1]);
            begin != end;
                ++begin
    )
        sum += fibo.next();

    cout << sum << '\n';
}
