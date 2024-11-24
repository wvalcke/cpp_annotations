#ifndef INCLUDED_RECURSIVEGENERATOR_H_
#define INCLUDED_RECURSIVEGENERATOR_H_

#include "promisebase.h"
#include "recursiveiterator.h"

template<typename T>
class [[nodiscard]] RecursiveGenerator
{
    class Promise: public PromiseBase              // final
    {
        using Handle = std::coroutine_handle<Promise>;

        class Awaitable
        {
            Promise *d_childPromise;

            public:
                Awaitable(Promise *childPromise);
                bool await_ready() noexcept;
                void await_resume();
                static void await_suspend(Handle) noexcept;
        };

            // If this is the promise of the root Generator then this field
            // is a pointer to the leaf promise.
            // For non-root Generators this is a pointer to the parent
            // promise:
        Promise *d_parentOrLeaf;
        T *d_value = 0;
        std::exception_ptr d_exception = 0;
        Promise *d_root;

        public:
            Promise() noexcept;
            Promise(Promise const &) = delete;

            auto get_return_object() noexcept;
            void unhandled_exception() noexcept;

            std::suspend_always yield_value(T &&value) noexcept;
            std::suspend_always yield_value(T &value) noexcept;

            auto yield_value(RecursiveGenerator &generator) noexcept;
            auto yield_value(RecursiveGenerator &&generator) noexcept;

            void destroy() noexcept;
            void throw_if_exception();
            bool is_complete() noexcept;
            T &value() noexcept;
            void pull() noexcept;

                // no 'co_await' inside the RecursiveGenerator coroutine.
            template<typename U>
            std::suspend_never await_transform(U&& value) = delete;

        private:
            void resume() noexcept;
    };

    Promise *d_promise;

    public:
        using promise_type = Promise;

        RecursiveGenerator() noexcept = default;
        RecursiveGenerator(Promise &promise) noexcept;
        RecursiveGenerator(RecursiveGenerator &&tmp) noexcept;

        ~RecursiveGenerator();

        RecursiveGenerator &operator=(RecursiveGenerator &&other)
                                                                noexcept;

        RecGenIterator<T, Promise> begin();
        RecGenIterator<T, Promise> end() noexcept;

        void swap(RecursiveGenerator &other) noexcept;
};

    // Note: When applying fmap operator to a RecursiveGenerator we just yield
    // a non-recursive Generator since we generally won't be using the result
    // in a recursive context.
template<typename FUNC, typename T>
Generator<
    std::invoke_result_t<
        FUNC &, typename RecursiveGenerator<T>::RecGenIterator::reference
    >
> fmap(FUNC func, RecursiveGenerator<T> source);

#include "recursivepromise.imp"
#include "recursivegenerator.imp"
#include "recursiveiterator.imp"

#endif
