#ifndef INCLUDED_RECURSIVE_
#define INCLUDED_RECURSIVE_

#include "../../promisebase/promisebase.h"

//interface
class Recursive
{
    class State: public PromiseBase<Recursive, State>
    {
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

        explicit Recursive(Handle handle);
        ~Recursive();

        size_t next();
        bool done() const;
};
//=

inline Recursive::Recursive(Handle handle)
:
    d_handle(handle)
{}

#endif
