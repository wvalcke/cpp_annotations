#ifndef INCLUDED_GENERATORPROMISE_H_
#define INCLUDED_GENERATORPROMISE_H_

#include <type_traits>
#include <exception>

#include "promisebase.h"

template<typename T>
class Generator;

template<typename T>
class Promise: public PromiseBase
{
    std::exception_ptr d_exception;
    std::remove_reference_t<T> *d_valuePtr;

    public:
        using Value = std::remove_reference_t<T>;
        using Reference = std::conditional_t<std::is_reference_v<T>, T, T&>;

        Generator<T> get_return_object() noexcept;

        template<
            typename U = T,
            std::enable_if_t<!std::is_rvalue_reference<U>::value, int> = 0>
        std::suspend_always yield_value(std::remove_reference_t<T>& value)
                                                                    noexcept;

        std::suspend_always yield_value(std::remove_reference_t<T>&& value)
                                                                    noexcept;
        void unhandled_exception();
        void rethrow_if_exception();

        Reference value() const noexcept;

            // Don't allow 'co_await' inside the Generator coroutine.
        template<typename U>
        std::suspend_never await_transform(U&& value) = delete;
};

#include "generatorpromise.imp"

#endif
