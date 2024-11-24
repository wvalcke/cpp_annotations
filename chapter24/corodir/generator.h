#ifndef INCLUDED_GENERATOR_H_
#define INCLUDED_GENERATOR_H_

template<typename T>
class [[nodiscard]] Generator
{
    friend class Promise<T>;

    using Handle = std::coroutine_handle<Promise<T>>;

    Handle d_handle = 0;

    public:
        using promise_type = Promise<T>;

        Generator() noexcept = default;

        Generator(Generator &&other) noexcept;
        ~Generator();

        Generator& operator=(Generator &&tmp) noexcept;

        Iterator<T> begin();
        Sentinel end() noexcept;

        void swap(Generator &other) noexcept;

    private:
        explicit Generator(Handle handle) noexcept;
};

#include "generator.imp"

#endif
