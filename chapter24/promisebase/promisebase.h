#ifndef INCLUDED_PROMISEBASE_
#define INCLUDED_PROMISEBASE_

//base
#include <cstddef>
#include <future>
#include <coroutine>

template <typename Handler, typename State>
struct PromiseBase
{
    Handler get_return_object();

    static std::suspend_always initial_suspend();
    static std::suspend_always final_suspend() noexcept;
    static void unhandled_exception();
    static void return_void();
};


template <typename Handler, typename State>
inline void PromiseBase<Handler, State>::return_void()
{}

template <typename Handler, typename State>
inline std::suspend_always PromiseBase<Handler, State>::initial_suspend()
{
    return {};
}

template <typename Handler, typename State>
inline std::suspend_always PromiseBase<Handler, State>::final_suspend() noexcept
{
    return {};
}

template <typename Handler, typename State>
inline void PromiseBase<Handler, State>::unhandled_exception()
{
    std::rethrow_exception(std::current_exception());
}

template <typename Handler, typename State>
inline Handler PromiseBase<Handler, State>::get_return_object()
{
    return Handler{ std::coroutine_handle<State>::from_promise(
                                                static_cast<State &>(*this) )
                  };
}
//=
#endif
