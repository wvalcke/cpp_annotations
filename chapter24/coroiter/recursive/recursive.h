#ifndef INCLUDED_RECURSIVE_
#define INCLUDED_RECURSIVE_

#include "../../promisebase/promisebase.h"

class Recursive
{
    class State: public PromiseBase<Recursive, State>
    {
        using Handle = std::coroutine_handle<State>;

        size_t d_level;
        size_t d_value;

        public:
            State(size_t level);
            static std::suspend_always initial_suspend();
            std::suspend_always yield_value(size_t value);
            size_t value() const;
            size_t level() const;
    };

    public:
        using Handle = std::coroutine_handle<State>;

    private:
        Handle d_handle;

    public:
        using promise_type = State;

//iter
    class Iterator
    {
        friend bool operator==(Iterator const &lhs, Iterator const &rhs);
        friend class Recursive;

        Handle d_handle;

        public:
            Iterator &operator++();
            size_t operator*() const;

        private:
            Iterator(Handle handle);
    };
//=

        explicit Recursive(std::coroutine_handle<State> handle);
        ~Recursive();

        bool next(size_t *value);
        void resume();

        Iterator begin();
        Iterator end();
};

inline bool operator==(Recursive::Iterator const &lhs,
                       Recursive::Iterator const &rhs)
{
    return lhs.d_handle.address() == rhs.d_handle.address();
}

inline Recursive::Recursive(std::coroutine_handle<State> handle)
:
    d_handle(handle)
{}

#endif
