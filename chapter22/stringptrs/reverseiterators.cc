    // compile only: members only declared, not implemented

#include <string>
#include <iterator>
#include <iostream>

struct Data
{
    class iterator;
    class const_iterator;

    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    private:
        std::string *d_data;
        size_t d_n;

    public:
        // ...
};

struct Data::iterator
{
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = std::string;
    using pointer           = value_type *;
    using reference         = value_type &;

    friend class Data;

    private:
        pointer d_current;

    public:
        iterator() = default;

        iterator &operator++();
        iterator &operator--();
        std::string &operator*();

    private:
        iterator(std::string *data, size_t idx);

        friend class std::reverse_iterator<iterator>;
};

bool operator==(Data::iterator const &lhs, Data::iterator const &rhs);

struct Data::const_iterator: public Data::iterator
{
    using const_pointer   = value_type const *;
    using const_reference = value_type const &;

    friend class Data;
    friend class std::reverse_iterator<const_iterator>;

    const_iterator() = default;

    const_iterator &operator++();
    const_iterator &operator--();

    const_reference operator*() const;
    // or, in this case: std::string const &operator*() const;

    private:
        const_iterator(std::string const *data, size_t idx);
};

bool operator==(Data::const_iterator const &lhs,
                Data::const_iterator const &rhs);


void demo()
{
    Data::iterator iter;
    Data::reverse_iterator riter(iter);

    std::cout << *riter << '\n';

    Data::const_iterator citer;
    Data::const_reverse_iterator criter(citer);

    std::cout << *criter << '\n';
};
