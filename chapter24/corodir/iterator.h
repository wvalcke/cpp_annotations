#ifndef INCLUDED_ITERATOR_H_
#define INCLUDED_ITERATOR_H_

// needs the Promise header (generatorpromise.h)

template <typename T>
class Iterator;

template<typename T>
bool operator==(Iterator<T> const &it, Sentinel) noexcept;

template<typename T>
class Iterator
{
    friend bool operator==<>(Iterator<T> const &it, Sentinel) noexcept;

    using Handle = std::coroutine_handle<Promise<T>>;

    Handle d_coHandle = 0;

    public:
        Iterator() noexcept = default;
        explicit Iterator(Handle handle) noexcept;

            // Need the post-increment operator for the 'Range' concept.
        void operator++(int);
        Iterator &operator++();

        typename Promise<T>::Reference operator*() const noexcept;
        typename Promise<T>::Value *operator->() const noexcept;
};

#include "iterator.imp"

#endif
