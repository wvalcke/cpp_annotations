#ifndef INCLUDED_RECURSIVE_
#define INCLUDED_RECURSIVE_

#include "../../promisebase/promisebase.h"

class Recursive
{
    class State: public PromiseBase<Recursive, State>
    {
        using Handle = std::coroutine_handle<State>;

        size_t d_value;

        public:
            std::suspend_always yield_value(size_t value);
            size_t value() const;
    };

    private:
        using Handle = std::coroutine_handle<State>;
        Handle d_handle;

    public:
        using promise_type = State;

        explicit Recursive(std::coroutine_handle<State> handle);
        ~Recursive();

        bool next(size_t *value);
};

inline Recursive::Recursive(std::coroutine_handle<State> handle)
:
    d_handle(handle)
{}

#endif
