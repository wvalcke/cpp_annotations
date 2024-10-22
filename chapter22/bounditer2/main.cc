#include <string>

//opequal
template <typename Type>
bool operator==(Type const &lhs, Type const &rhs);
//=

template <typename Type>
struct String
{
    struct iterator
    {
        std::string::iterator d_iter;

        friend bool operator==<>(iterator const &lhs, iterator const &rhs);
    };

    iterator begin()
    {
        return iterator{};
    }
};

//code
template <typename Type>
inline bool operator==(String<Type>::iterator const &lhs,
                       String<Type>::iterator const &rhs)
{
    return lhs.d_iter == rhs.d_iter;
}
//=

int main()
{
    String<int> str;
    return str.begin() == str.begin();
}
