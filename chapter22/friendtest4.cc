//#include <iostream>
#include <string>

// the following conflicts, as std::iterator is defined and conflicts with struct iterator
//using namespace std;

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

/*
* Waarom geen template <typename Type, typename Type::StringType_iterator = 0>
* 2e template argument is een non type parameter, dus gaan we al zeker geen typename er voor zetten
* De compiler weet dus dat Type::StringTye_iterator effectief een type moet zijn en kan dit dus 
* niet verkeerd interpreteren als een static in Type 'type' bvb wat anders wel gebeurt.
* Als we bij lhs of rhs bvb zouden verwijzen naar Type::StringType_iterator zouden we wel
* typename er moeten voorzetten.
*/
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

int main(int argc, char* argv[])
{
    String<int> str;
    Container<int> cnt;
    return str.begin() == str.begin() and cnt.begin() == cnt.begin();
}
