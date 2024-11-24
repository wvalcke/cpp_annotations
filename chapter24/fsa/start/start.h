#ifndef INCLUDED_START_
#define INCLUDED_START_

#include "../../promisebase/promisebase.h"
#include "../awaiter/awaiter.h"

#include "../letter/letter.h"
#include "../digit/digit.h"
#include "../done/done.h"

// no operator co_await -> Start is the Awaiter

//start
class Start: public Awaiter
{
    struct State: public PromiseBase<Start, State>
    {};

    std::coroutine_handle<State> d_handle;

    public:
        using promise_type = State;
        using Handle = std::coroutine_handle<State>;

        explicit Start(Handle handle);
        ~Start();

        void go();

                // this and the  members in Awaiter are required for Awaiters
        template <typename HandleType>
        std::coroutine_handle<State> await_suspend(HandleType &handle);
};

template <typename HandleType>
inline std::coroutine_handle<Start::State>
                                  Start::await_suspend(HandleType &handle)
{
    return d_handle;
}
//=

extern Start g_start;

#endif
