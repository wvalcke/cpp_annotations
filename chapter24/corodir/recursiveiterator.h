template <typename T, typename Promise>
class RecGenIterator
{
    Promise *d_promise = 0;

    public:
        using Reference = std::conditional_t<std::is_reference_v<T>, T, T &>;

        RecGenIterator() noexcept = default;

        explicit RecGenIterator(Promise *promise) noexcept;

        bool operator==(RecGenIterator const &other) const noexcept;

        bool operator!=(RecGenIterator const &other) const noexcept;

        RecGenIterator &operator++();

        void operator++(int);

        Reference operator*() const noexcept;

        T *operator->() const noexcept;
};
