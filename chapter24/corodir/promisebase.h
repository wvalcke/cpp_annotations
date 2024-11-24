#ifndef INCLUDED_PROMISEBASE_H_
#define INCLUDED_PROMISEBASE_H_

class PromiseBase
{
    public:
        std::suspend_always initial_suspend();
        std::suspend_always final_suspend() noexcept;
        [[noreturn]] void unhandled_exception();
        void return_void();
};

inline std::suspend_always PromiseBase::initial_suspend()
{
    return {};
}

inline std::suspend_always PromiseBase::final_suspend() noexcept
{
    return {};
}

inline void PromiseBase::unhandled_exception()
{
    throw;
}

inline void PromiseBase::return_void()
{}

#endif
