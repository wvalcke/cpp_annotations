#include <string>

//classes
template <typename Type>
struct String
{
    struct iterator
    {
        using StringType_iterator = int;
        friend bool operator==<>(iterator const &lhs, iterator const &rhs);

        std::string::iterator d_iter;
    };
    iterator begin()
    {
        return iterator{};
    }
};

template <typename Type>
struct Container
{
    struct iterator
    {
        using ContainerType_iterator = int;
        friend bool operator==<>(iterator const &lhs, iterator const &rhs);

        int *d_ptr;
    };
    iterator begin()
    {
        return iterator{};
    }
};
//=

//code
template <typename Type, Type::StringType_iterator = 0>
inline bool operator==(Type const &lhs, Type const &rhs)
{
    return lhs.d_iter == rhs.d_iter;
}

template <typename Type, Type::ContainerType_iterator = 0>
inline bool operator==(Type const &lhs, Type const &rhs)
{
    return lhs.d_ptr == rhs.d_ptr;
}
//=

//main
int main()
{
    String<int> str;
    Container<int> cnt;
    return str.begin() == str.begin() and cnt.begin() == cnt.begin();
}
//=
