#ifndef INCLUDED_STRINGPTR_H_
#define INCLUDED_STRINGPTR_H_

#include <string>
#include <vector>
#include <iterator>
#include <compare>

//STRINGPTR
struct StringPtr: public std::vector<std::string *>
{
    class iterator;
    using reverse_iterator = std::reverse_iterator<iterator>;

    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};

struct StringPtr::iterator
{
//USING
    using iterator_category = std::random_access_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = std::string;
    using pointer           = value_type *;
    using reference         = value_type &;
//=

    friend class StringPtr;

    friend bool operator==(iterator const &lhs, iterator const &rhs);
    friend auto operator<=>(iterator const &lhs, iterator const &rhs);
    friend int operator-(iterator const &lhs, iterator const &rhs);
    friend iterator operator+(iterator const &lhs, int step);
    friend iterator operator-(iterator const &lhs, int step);

    private:
        std::vector<std::string *>::iterator d_current;

    public:
        iterator &operator--();
        iterator operator--(int);
        iterator &operator++();
        iterator operator++(int);

        iterator &operator+=(int step); // increment over `n' steps
        iterator &operator-=(int step); // decrement over `n' steps

        std::string &operator*() const;
        std::string *operator->() const;// access the fields of the
                                        // struct an iterator points
                                        // to. E.g., it->length()
    private:
        iterator(std::vector<std::string *>::iterator const &current);
};
//=

//PRIVATEIMP
inline StringPtr::iterator::iterator(
    std::vector<std::string *>::iterator const &current)
:
    d_current(current)
{}
//=

//PREDEC
inline StringPtr::iterator &StringPtr::iterator::operator--()
{
    --d_current;
    return *this;
}
//=
//POSTDEC
inline StringPtr::iterator StringPtr::iterator::operator--(int)
{
    return iterator(d_current--);
}
//=
//PREINC
inline StringPtr::iterator &StringPtr::iterator::operator++()
{
    ++d_current;
    return *this;
}
//=
//POSTINC
inline StringPtr::iterator StringPtr::iterator::operator++(int)
{
    return iterator(d_current++);
}
//=
//OPEQ
inline bool operator==(StringPtr::iterator const &lhs,
                       StringPtr::iterator const &rhs)
{
    return lhs.d_current == rhs.d_current;
}
//=
//OPSPACE
inline auto operator<=>(StringPtr::iterator const &lhs,
                        StringPtr::iterator const &rhs)
{
    return lhs.d_current <=> rhs.d_current;
}
//=
//OPSUB
inline int operator-(StringPtr::iterator const &lhs,
                     StringPtr::iterator const &rhs)
{
    return lhs.d_current - rhs.d_current;
}
//=
//OP*
inline std::string &StringPtr::iterator::operator*() const
{
    return **d_current;
}
//=
//=
//OPADD
inline StringPtr::iterator operator+(StringPtr::iterator const &lhs,
                                                                int step)
{
    StringPtr::iterator ret{ lhs };
    ret.d_current += step;          // avoids ambiguity
    return ret;
}
//=
//OP-
inline StringPtr::iterator operator-(StringPtr::iterator const &lhs,
                                                                int step)
{
    StringPtr::iterator ret{ lhs };
    ret.d_current -= step;          // avoids ambiguity
    return ret;
}
//=
//OPARITH
inline StringPtr::iterator &StringPtr::iterator::operator+=(int step)
{
    d_current += step;
    return *this;
}
inline StringPtr::iterator &StringPtr::iterator::operator-=(int step)
{
    d_current -= step;
    return *this;
}
//=
//OPARROW
inline std::string *StringPtr::iterator::operator->() const
{
    return *d_current;
}
//=
//BEGEND
inline StringPtr::iterator StringPtr::begin()
{
    return iterator(std::vector<std::string *>::begin());
}
inline StringPtr::iterator StringPtr::end()
{
    return iterator(std::vector<std::string *>::end());
}
//=
//RBEGEND
inline StringPtr::reverse_iterator StringPtr::rbegin()
{
    return reverse_iterator(end());
}
inline StringPtr::reverse_iterator StringPtr::rend()
{
    return reverse_iterator(begin());
}
//=

#endif
