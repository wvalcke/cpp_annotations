#ifndef INCLUDED_READER_
#define INCLUDED_READER_

    // use return_value if an expression is passed to co_return

//interface
#include <iostream>
#include <optional>

#include "../../promisebase/promisebase.h"

struct Reader
{
    using ValueType = std::optional<float>;

    private:
        class State: public PromiseBase<Reader, State>
        {
            ValueType d_value;

            public:
                std::suspend_always yield_value(float value);
                void return_void();
                ValueType const &value() const;
        };

        std::coroutine_handle<State> d_handle;

    public:
        using promise_type = State;

        explicit Reader(std::coroutine_handle<State> handle);
        ~Reader();

        ValueType const &next();
};
//=

// OK (declaration)  std::suspend_always await_transform(float value);

// OK inline std::suspend_always Reader::State::await_transform(float value)
// OK {
// OK     d_value = value;
// OK     return {};
// OK }


//defs
inline std::suspend_always Reader::State::yield_value(float value)
{
    d_value = value;
    return {};
}

inline void Reader::State::return_void()
{
    d_value = ValueType{};
}

inline Reader::ValueType const &Reader::State::value() const
{
    return d_value;
}

inline Reader::Reader(std::coroutine_handle<State> handle)
:
    d_handle(handle)
{}

inline Reader::~Reader()
{
    if (d_handle)
        d_handle.destroy();
}
//=

#endif
