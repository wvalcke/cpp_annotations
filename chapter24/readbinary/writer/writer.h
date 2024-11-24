#ifndef INCLUDED_WRITER_
#define INCLUDED_WRITER_

    // use return_value if an expression is passed to co_return

#include <iostream>
#include <optional>

#include "../../promisebase/promisebase.h"

//writer
struct Writer
{
    using ValueType = std::optional<std::string>;

    private:
        class State: public PromiseBase<Writer, State>
        {
            ValueType d_value;

            public:
                std::suspend_always yield_value(ValueType &value);
                void return_void();
                ValueType const &value() const;
        };

        std::coroutine_handle<State> d_handle;

    public:
        using promise_type = State;

        explicit Writer(std::coroutine_handle<State> handle);
        ~Writer();

        ValueType const &next();
};

inline std::suspend_always Writer::State::yield_value(ValueType &value)
{
    d_value = std::move(value);
    return {};
}
//=

inline void Writer::State::return_void()
{
    d_value = ValueType{};
}

inline Writer::ValueType const &Writer::State::value() const
{
    return d_value;
}

inline Writer::Writer(std::coroutine_handle<State> handle)
:
    d_handle(handle)
{}

inline Writer::~Writer()
{
    if (d_handle)
        d_handle.destroy();
}


#endif
